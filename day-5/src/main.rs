use regex::Regex;
use std::io::{self, BufRead};
use std::mem;

const CRATE_CHAR_SPACING: usize = 4;

fn main() {
    let mut stacks = read_stacks();
    let move_re = Regex::new(r"move (\d+) from (\d+) to (\d+)").unwrap();

    let stdin = io::stdin();
    let mut swap_vecs = Some((vec![], vec![]));
    for line in stdin.lock().lines() {
        let line = line.expect("expected to read line");
        if let Some(cap) = move_re.captures(&line) {
            let num = get_group_int(&cap, 1);
            let from = get_group_int(&cap, 2) - 1;
            let to = get_group_int(&cap, 3) - 1;

            // little hackery here since we can't get mutable references to
            // multiple to vector indicies at once. So instead we swap out
            // the stacks with the always-empty 'swap vecs', and put them
            // back in at the.
            let swap_tmp = swap_vecs.take().unwrap();
            let mut from_s = mem::replace(&mut stacks[from], swap_tmp.0);
            let mut to_s = mem::replace(&mut stacks[to], swap_tmp.1);

            // part 1:
            // for _ in 0..num {
            //     let item = from_s.pop().expect("expected to have item to take");
            //     to_s.push(item);
            // }

            // part 2:
            to_s.extend_from_slice(&from_s[from_s.len() - num..]);
            from_s.truncate(from_s.len() - num);

            swap_vecs = Some((
                mem::replace(&mut stacks[from], from_s),
                mem::replace(&mut stacks[to], to_s),
            ))
        }
    }

    println!("stack tops:");
    for s in stacks {
        if s.is_empty() {
            println!("empty")
        } else {
            println!("{}", s[s.len() - 1]);
        }
    }
}

fn get_group_int(cap: &regex::Captures, group: usize) -> usize {
    cap.get(group)
        .expect("missing group in regex")
        .as_str()
        .parse::<usize>()
        .expect("expected to parse match as int")
}

fn read_stacks() -> Vec<Vec<char>> {
    let mut stacks: Vec<Vec<char>> = vec![];
    for line in io::stdin().lock().lines() {
        let line = line.expect("expected to read line");
        if line.is_empty() {
            // grid reading finish, last line was just numbers. Pop that and
            // reverse them so the bottom of the stack is index 0.
            for stack in &mut stacks {
                stack.pop();
                stack.reverse();
            }
            return stacks;
        }

        let line = line.as_bytes();

        // first item is at char 1, then each other item is four chars after that
        for i in (1..line.len()).step_by(CRATE_CHAR_SPACING) {
            let n = i / CRATE_CHAR_SPACING;
            if stacks.len() <= n {
                stacks.push(vec![]);
            }

            match line.get(i).map(|c| *c as char) {
                Some(b) if b != ' ' => stacks.get_mut(n).unwrap().push(b),
                _ => {}
            }
        }
    }

    stacks
}
