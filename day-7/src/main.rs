use std::collections::HashMap;
use std::fmt::Write;
use std::io::{self, BufRead};

enum Child {
    File(File),
    Directory(Directory),
}

struct File {
    size: u64,
}

#[derive(Default)]
struct Directory {
    total_size: u64,
    children: HashMap<String, Child>,
}

impl Directory {
    /// Recursively filters for directories, returning the outcome of the
    /// directories that return Some from the filter.
    pub fn filter_dirs<T, F>(&self, filter: F) -> Vec<T>
    where
        F: Copy + Fn(&Directory) -> Option<T>,
    {
        let mut v = vec![];
        self.filter_dirs_inner(&mut v, filter);
        v
    }
    pub fn filter_dirs_inner<T, F>(&self, out: &mut Vec<T>, filter: F)
    where
        F: Copy + Fn(&Directory) -> Option<T>,
    {
        for child in self.children.values() {
            if let Child::Directory(d) = &child {
                if let Some(t) = filter(d) {
                    out.push(t);
                }

                d.filter_dirs_inner(out, filter)
            }
        }
    }

    pub fn total_size(&self) -> u64 {
        self.total_size
    }

    fn add_to_string(&self, s: &mut String, indent: usize) {
        let prefix = " ".repeat(indent * 2);
        for (name, child) in &self.children {
            match child {
                Child::File(f) => {
                    s.write_fmt(format_args!(
                        "{}- {} (file, size={})\n",
                        prefix, name, f.size
                    ))
                    .unwrap();
                }
                Child::Directory(d) => {
                    s.write_fmt(format_args!(
                        "{}- {} (dir, size={})\n",
                        prefix,
                        name,
                        d.total_size()
                    ))
                    .unwrap();
                    d.add_to_string(s, indent + 1);
                }
            }
        }
    }

    #[allow(dead_code)]
    pub fn to_string(&self) -> String {
        let mut s = String::new();
        self.add_to_string(&mut s, 0);
        s
    }
}

const CD_PREFIX: &str = "$ cd ";
const LS_PREFIX: &str = "$ ls";
const LS_DIR_PREFIX: &str = "dir ";

const TOTAL_DISK_SPACE: u64 = 70000000;
const NEEDED_DISK_SPACE: u64 = 30000000;

type Stack = Vec<(String, Directory)>;

fn main() {
    let stdin = io::stdin();

    let mut stack: Stack = vec![(String::new(), Directory::default())];

    for line in stdin.lock().lines() {
        let line = line.expect("expected to read line");

        if line.is_empty() {
            continue;
        } else if let Some(name) = line.strip_prefix(CD_PREFIX) {
            match name {
                ".." => cd_up_one_level(&mut stack),
                "/" => cd_to_root(&mut stack),
                name => cd_to_child(&mut stack, name),
            }
        } else if line.starts_with(LS_PREFIX) {
            // ignore, next lines will start adding things...
        } else if let Some(name) = line.strip_prefix(LS_DIR_PREFIX) {
            stack
                .last_mut()
                .unwrap()
                .1
                .children
                .insert(name.to_owned(), Child::Directory(Directory::default()));
        } else if let Some(idx) = line.find(' ') {
            // assume `<size> <file>`
            let size = line[..idx].parse::<u64>().expect("expected to parse size");
            let last = stack.last_mut().unwrap();
            last.1.total_size += size;
            last.1
                .children
                .insert(line[idx + 1..].to_owned(), Child::File(File { size }));
        } else {
            panic!("could not parse line: {}", line);
        }
    }

    cd_to_root(&mut stack);

    let root = stack.last().expect("expected root");
    let root = &root.1;

    let small_dirs: u64 = root
        .filter_dirs(|d| (d.total_size() <= 100_000).then(|| d.total_size()))
        .into_iter()
        .sum();

    println!("total size of small dirs: {}", small_dirs);

    let needed_disk_space = NEEDED_DISK_SPACE - (TOTAL_DISK_SPACE - root.total_size);
    let best_candidate = root
        .filter_dirs(|d| (d.total_size() >= needed_disk_space).then(|| d.total_size()))
        .into_iter()
        .min();

    println!("smallest dir to delete to make space: {:?}", best_candidate);
}

fn cd_to_child(stack: &mut Stack, name: &str) {
    let last = stack.last_mut().unwrap();
    match last.1.children.remove(name) {
        Some(Child::Directory(c)) => {
            last.1.total_size -= c.total_size;
            stack.push((name.to_owned(), c));
        }
        Some(Child::File(_)) => panic!("cannot cd into file {}", name),
        None => panic!("cannot find directory {}", name),
    }
}

fn cd_to_root(stack: &mut Stack) {
    while stack.len() > 1 {
        cd_up_one_level(stack);
    }
}

fn cd_up_one_level(stack: &mut Stack) {
    if stack.len() <= 1 {
        return;
    }

    // length is checked to be at least 2:
    let (name, dir) = unsafe { stack.pop().unwrap_unchecked() };
    let last = unsafe { stack.last_mut().unwrap_unchecked() };
    last.1.total_size += dir.total_size;
    last.1.children.insert(name, Child::Directory(dir));
}
