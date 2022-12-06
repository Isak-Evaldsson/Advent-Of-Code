/*
    Advent of Code 2022 - by Isak Evaldssson
    Day 6: Tuning Trouble
*/

use std::{collections::HashSet, env, io};

fn find_packet_start(window_size: usize) -> usize {
    let offset = window_size - 1;
    let input: String = io::stdin().lines().map(|x| x.unwrap()).nth(0).unwrap();

    // Apply our sliding window
    for (index, _) in input.char_indices().filter(|(i, _)| *i >= offset) {
        let window: HashSet<char> = HashSet::from_iter(input[index - offset..index + 1].chars());

        if window.len() > offset {
            return index + 1;
        }
    }
    return 0;
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("Usage: {} task[1,2] < input", args[0]);
        return;
    }

    let task = &args[1];
    if task == "task1" {
        println!("Task 1: start-of-packet {}", find_packet_start(4));
    } else if task == "task2" {
        println!("Task 2: start-of-packet {}", find_packet_start(14));
    } else {
        println!("Invalid task {}", args[1]);
    }
}
