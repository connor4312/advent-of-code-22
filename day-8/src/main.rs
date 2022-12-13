use std::io::{self, BufRead};

const MAX_HEIGHT: usize = 9;

#[derive(Default)]
struct Tree {
    height: u8,
    // Trees that this one from the edges, at n, e, s, and w
    hidden_at: [Option<usize>; 4],
    // Nearest tree that blocks the view, at n, e, s, and w
    blocks_at: [Option<usize>; 4],
}

impl Tree {
    pub fn is_visible(&self) -> bool {
        for x in self.hidden_at {
            if x.is_none() {
                return true;
            }
        }

        false
    }

    pub fn seen_trees(&self, own_index: usize, forest_size: usize, width: usize) -> usize {
        let n = (own_index - self.blocks_at[0].unwrap_or(0)) / width;
        let s = (self.blocks_at[2].unwrap_or(forest_size) - own_index) / width;

        let own_row_start = (own_index / width) * width;
        let w = own_index - self.blocks_at[3].unwrap_or(own_row_start);
        let e = self.blocks_at[1].unwrap_or(own_row_start + width - 1) - own_index;

        n * e * s * w
    }
}

fn main() {
    let mut forest: Vec<Tree> = vec![];
    let mut width = 0;

    let stdin = io::stdin();
    for line in stdin.lock().lines() {
        let line = line.expect("expected to read line");
        if line.is_empty() {
            continue;
        }

        width = line.len();
        forest.extend(
            line.chars()
                .map(|chr| (chr as u8) - b'0')
                .map(|height| Tree {
                    height,
                    ..Default::default()
                }),
        );
    }

    mark_visible(&mut forest, width);

    let total_visible = forest.iter().filter(|t| t.is_visible()).count();
    println!("{} trees visible", total_visible);

    let most_scenic = forest
        .iter()
        .enumerate()
        .map(|(i, t)| t.seen_trees(i, forest.len(), width))
        .max();
    println!("{:?} most scenic", most_scenic);
}

fn mark_visible(forest: &mut Vec<Tree>, width: usize) {
    let len = forest.len();
    for y in 1..width {
        mark_visible_in_direction(forest, 0, (y..len).step_by(width)); // N->S
        mark_visible_in_direction(forest, 2, (y..len).step_by(width).rev()); // S->N
    }

    for x in (0..len).step_by(width) {
        mark_visible_in_direction(forest, 3, x..x + width); // W->E
        mark_visible_in_direction(forest, 1, (x..x + width).rev()); // E->W
    }
}

fn mark_visible_in_direction(
    forest: &mut [Tree],
    blocked_dir: usize,
    mut it: impl Iterator<Item = usize>,
) {
    let first = match it.next() {
        None => return,
        Some(u) => u,
    };

    let mut blocked_at_height = [None; MAX_HEIGHT + 1];
    let mut max_height = forest[first].height;
    let mut max_index = first;
    blocked_at_height[max_height as usize] = Some(first);

    for i in it {
        let tree = &mut forest[i];
        if tree.height > max_height {
            max_height = tree.height;
            max_index = i;
        } else {
            tree.hidden_at[blocked_dir] = Some(max_index)
        }

        tree.blocks_at[blocked_dir] = blocked_at_height[tree.height as usize];
        for h in 0..=tree.height {
            blocked_at_height[h as usize] = Some(i);
        }
    }
}
