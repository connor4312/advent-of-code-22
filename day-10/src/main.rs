use std::io::{self, BufRead};

const INTERESTING_CYCLES: [usize; 6] = [20, 60, 100, 140, 180, 220];
const ADDX_PREFIX: &str = "addx ";
const NOOP_PREFIX: &str = "noop";

const CRT_WIDTH: usize = 40;
const CRT_HEIGHT: usize = 6;

fn main() {
    let stdin = io::stdin();
    let mut answer = 0;

    let mut x = 1;
    let mut cycle = 1;

    let mut crt = vec![false; CRT_HEIGHT * CRT_WIDTH];

    for line in stdin.lock().lines() {
        let line = line.expect("expected to read line");
        if line.is_empty() {
            continue;
        }

        let (advance, incr) = if let Some(amt) = line.strip_prefix(ADDX_PREFIX) {
            let amt = amt.parse::<i64>().expect("expected to parse addx");
            (2, amt)
        } else if line.starts_with(NOOP_PREFIX) {
            (1, 0)
        } else {
            panic!("unexpected line {}", line)
        };

        if let Some(c) = INTERESTING_CYCLES
            .iter()
            .find(|c| **c >= cycle && **c < cycle + advance)
        {
            answer += (*c as i64) * x;
        }

        for _ in 0..advance {
            let scan_x = ((cycle - 1) % CRT_WIDTH) as i64;
            crt[cycle - 1] = (scan_x - x).abs() <= 1;
            cycle += 1;
        }

        x += incr;
    }

    println!("answer: {}", answer);

    let mut crt_display = String::with_capacity(CRT_HEIGHT * (CRT_WIDTH + 1));
    for x in 0..CRT_WIDTH * CRT_HEIGHT {
        crt_display.push(if crt[x] { '#' } else { '.' });
        if (x + 1) % CRT_WIDTH == 0 {
            crt_display.push('\n');
        }
    }

    print!("{}", crt_display);
}
