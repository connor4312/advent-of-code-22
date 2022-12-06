use std::{collections::HashMap, io};

fn main() {
    let mut buffer = String::new();
    io::stdin()
        .read_line(&mut buffer)
        .expect("expected to read line");
    let buffer = buffer.as_bytes();

    let start_of_packet = match get_unique_sequence(buffer, 4) {
        Some(n) => n,
        None => panic!("no start of packet detected"),
    };
    println!("start of packet: {}", start_of_packet);

    let start_of_message = match get_unique_sequence(&buffer[start_of_packet..], 14) {
        Some(n) => n + start_of_packet,
        None => panic!("no start of message detected"),
    };
    println!("start of message: {}", start_of_message);
}

fn get_unique_sequence(buffer: &[u8], sequence_len: usize) -> Option<usize> {
    // maybe a more naive iterative solution would be faster. And I did that
    // with part 1 with sequence_length = 4, but with 14, perhaps a hashmap is better...

    let mut count_map = HashMap::new();

    for i in 0..buffer.len() {
        count_map
            .entry(buffer[i])
            .and_modify(|c| *c += 1)
            .or_insert(1);

        if i >= sequence_len {
            let to_remove = buffer[i - sequence_len];
            match count_map.get(&to_remove).copied() {
                Some(1) => count_map.remove(&to_remove),
                Some(n) => count_map.insert(to_remove, n - 1),
                _ => unreachable!(),
            };
        }

        if count_map.len() == sequence_len {
            return Some(i + 1);
        }
    }

    None
}
