use std::io::{self, BufRead};

const TOP_CALS: usize = 3;

fn main() {
    let stdin = io::stdin();

    let mut cur_cals = 0;
    let mut max_cals = vec![0; TOP_CALS + 1];
    for line in stdin.lock().lines() {
        let line = line.expect("expected to read line");
        let line = line.trim();
        if line.is_empty() {
            max_cals[0] = cur_cals;
            max_cals.sort_unstable();
            cur_cals = 0;
            continue;
        }

        cur_cals += line.parse::<u64>().expect("expected to parse line");
    }

    println!("Top {} carriers:", TOP_CALS);
    let mut total = 0;
    for x in 1..(TOP_CALS + 1) {
        let n = max_cals[x];
        total += n;
        println!("{}", n);
    }

    println!("Total: {}", total);
}
