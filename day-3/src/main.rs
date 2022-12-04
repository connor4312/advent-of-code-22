use std::{
    collections::HashSet,
    io::{self, BufRead},
};

fn char_to_priority(chr: char) -> u64 {
    if chr >= 'a' && chr <= 'z' {
        1 + (chr as u64) - ('a' as u64)
    } else if chr >= 'A' && chr <= 'Z' {
        27 + (chr as u64) - ('A' as u64)
    } else {
        panic!("unexpected character {}", chr)
    }
}

fn main() {
    // part 2 involved destroying part 1's solution. Sorry.

    let stdin = io::stdin();

    let mut total = 0;
    let mut group_i = 0;
    let mut group_set = HashSet::new();

    for line in stdin.lock().lines() {
        let line = line.expect("expected to read line");
        if line.is_empty() {
            continue;
        }

        let own_set = line.chars().collect::<HashSet<_>>();
        if group_i == 0 {
            group_set = own_set;
        } else {
            group_set.retain(|chr| own_set.contains(chr));
        }

        if group_i == 2 {
            assert_eq!(group_set.len(), 1);
            total += char_to_priority(*group_set.iter().next().unwrap());
            group_i = 0;
            group_set.clear();
        } else {
            group_i += 1;
        }
    }

    println!("{}", total);
}
