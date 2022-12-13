use std::{
    collections::HashSet,
    io::{self, BufRead},
};

const KNOT_COUNT: usize = 10;

fn main() {
    let stdin = io::stdin();

    let mut segments: [(i32, i32); KNOT_COUNT] = [(0, 0); KNOT_COUNT];
    let mut tail_visited = HashSet::new();
    tail_visited.insert((0, 0));

    for line in stdin.lock().lines() {
        let line = line.expect("expected to read line");
        let line = line.trim();
        if line.is_empty() {
            continue;
        }

        let instruction = line.chars().next();
        let n = line[2..]
            .parse::<i32>()
            .expect("expected to parse movement");

        for _ in 0..n {
            match instruction {
                Some('R') => segments[0].1 += 1,
                Some('L') => segments[0].1 -= 1,
                Some('U') => segments[0].0 += 1,
                Some('D') => segments[0].0 -= 1,
                _ => unreachable!(),
            };

            for i in 0..(KNOT_COUNT - 1) {
                let cur = segments[i];
                let prev = segments[i + 1];

                let diff = (cur.0 - prev.0, cur.1 - prev.1);
                if diff.0.abs() <= 1 && diff.1.abs() <= 1 {
                    break;
                }

                segments[i + 1] = (prev.0 + diff.0.clamp(-1, 1), prev.1 + diff.1.clamp(-1, 1));
                if i == KNOT_COUNT - 2 {
                    tail_visited.insert(segments[i + 1]);
                }
            }
        }
    }

    println!("visited tail locations: {}", tail_visited.len());
}
