use std::io::{self, BufRead};

#[derive(Clone, Copy, PartialEq, Eq)]
enum Outcome {
    Win,
    Draw,
    Loss,
}

impl Outcome {
    fn score(&self) -> u64 {
        match self {
            Outcome::Win => 6,
            Outcome::Draw => 3,
            Outcome::Loss => 0,
        }
    }
}

impl TryFrom<char> for Outcome {
    type Error = io::Error;

    fn try_from(value: char) -> Result<Self, Self::Error> {
        match value {
            // note: x/y/z are not used in part 2
            'X' => Ok(Outcome::Loss),
            'Y' => Ok(Outcome::Draw),
            'Z' => Ok(Outcome::Win),
            _ => Err(io::Error::new(
                io::ErrorKind::InvalidData,
                format!("bad character {}", value),
            )),
        }
    }
}

#[derive(Clone, Copy, PartialEq, Eq)]
enum Guess {
    Rock,
    Paper,
    Scissors,
}

impl TryFrom<char> for Guess {
    type Error = io::Error;

    fn try_from(value: char) -> Result<Self, Self::Error> {
        match value {
            // note: x/y/z are not used in part 2
            'A' | 'X' => Ok(Guess::Rock),
            'B' | 'Y' => Ok(Guess::Paper),
            'C' | 'Z' => Ok(Guess::Scissors),
            _ => Err(io::Error::new(
                io::ErrorKind::InvalidData,
                format!("bad character {}", value),
            )),
        }
    }
}

const OUTCOME_TABLE: [(Guess, Guess, Outcome); 9] = [
    (Guess::Rock, Guess::Paper, Outcome::Loss),
    (Guess::Rock, Guess::Scissors, Outcome::Win),
    (Guess::Rock, Guess::Rock, Outcome::Draw),
    //
    (Guess::Paper, Guess::Rock, Outcome::Win),
    (Guess::Paper, Guess::Scissors, Outcome::Loss),
    (Guess::Paper, Guess::Paper, Outcome::Draw),
    //
    (Guess::Scissors, Guess::Paper, Outcome::Win),
    (Guess::Scissors, Guess::Rock, Outcome::Loss),
    (Guess::Scissors, Guess::Scissors, Outcome::Draw),
];

impl Guess {
    /// Returns the guess that would result in the given outcome, when calling `ret.outcome(opponent_play)`
    fn from_outcome(opponent_play: Guess, outcome: Outcome) -> Guess {
        for (g_self, g_opp, expected) in &OUTCOME_TABLE {
            if g_opp == &opponent_play && expected == &outcome {
                return *g_self;
            }
        }

        unreachable!();
    }

    fn score(&self) -> u64 {
        match self {
            Guess::Rock => 1,
            Guess::Paper => 2,
            Guess::Scissors => 3,
        }
    }

    fn outcome(&self, opponent_play: Guess) -> Outcome {
        for (g_self, g_opp, outcome) in &OUTCOME_TABLE {
            if g_self == self && g_opp == &opponent_play {
                return *outcome;
            }
        }

        unreachable!();
    }
}

fn main() {
    let stdin = io::stdin();

    let mut score = 0;
    for line in stdin.lock().lines() {
        let line = line.expect("expected to read line");
        if line.is_empty() {
            continue;
        }

        let line = line.as_bytes();
        let opponent_play: Guess = (line[0] as char).try_into().unwrap();
        let desired_outcome: Outcome = (line[2] as char).try_into().unwrap();
        let own_play = Guess::from_outcome(opponent_play, desired_outcome);

        score += own_play.score() + desired_outcome.score();
    }

    println!("score: {}", score)
}
