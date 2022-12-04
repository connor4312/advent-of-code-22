use std::io::{self, BufRead};

struct Range(u64, u64);

impl TryFrom<&str> for Range {
    type Error = io::Error;

    fn try_from(value: &str) -> Result<Self, Self::Error> {
        let split = value.find('-').ok_or_else(|| {
            io::Error::new(io::ErrorKind::InvalidData, "could not find - in group")
        })?;

        let start = value[0..split]
            .parse::<u64>()
            .map_err(|_| io::Error::new(io::ErrorKind::InvalidData, "could not parse start"))?;
        let end = value[split + 1..]
            .parse::<u64>()
            .map_err(|_| io::Error::new(io::ErrorKind::InvalidData, "could not parse end"))?;

        Ok(Self(start, end))
    }
}

impl Range {
    pub fn contains(&self, other: &Range) -> bool {
        self.0 <= other.0 && self.1 >= other.1
    }

    pub fn overlaps(&self, other: &Range) -> bool {
        (self.0 <= other.1 && self.0 >= other.0) || (self.1 <= other.1 && self.1 >= other.0)
    }
}

fn main() {
    // part 2 involved destroying part 1's solution. Sorry.

    let stdin = io::stdin();

    let mut fully_contained = 0;
    let mut overlaps = 0;

    for line in stdin.lock().lines() {
        let line = line.expect("expected to read line");
        if line.is_empty() {
            continue;
        }

        let split = line.find(',').expect("expected to find a ,");
        let a = Range::try_from(&line[0..split]).unwrap();
        let b = Range::try_from(&line[split + 1..]).unwrap();
        if a.contains(&b) || b.contains(&a) {
            fully_contained += 1;
        }
        if a.overlaps(&b) || b.overlaps(&a) {
            overlaps += 1;
        }
    }

    println!("number fully contained: {}", fully_contained);
    println!("number overlaps: {}", overlaps);
}
