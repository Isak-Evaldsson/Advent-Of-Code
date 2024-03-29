/*
    Advent of Code 2022 - by Isak Evaldssson
    Day 3: Rucksack Reorganization
*/

use std::{env, io};

fn score(c: char) -> u8 {
    if c.is_uppercase() {
        (c as u8) - ('A' as u8) + 27
    } else {
        (c as u8) - ('a' as u8) + 1
    }
}

fn task1() {
    let mut sum: u32 = 0;

    for line in io::stdin().lines() {
        let str = line.unwrap();
        let divider = str.len() / 2;
        let compartment1 = &str[..divider];
        let compartment2 = &str[divider..];

        let duplicate = compartment1
            .chars()
            .find(|c| compartment2.contains(*c))
            .unwrap();

        sum += score(duplicate) as u32;
    }
    println!("Task 1: Sum of priorities {}", sum);
}

fn task2() {
    let mut sum: u32 = 0;
    let lines: Vec<String> = io::stdin().lines().map(|x| x.unwrap()).collect();

    for i in (0..lines.len()).step_by(3) {
        let badge = lines[i]
            .chars()
            .find(|c| lines[i + 1].contains(*c) && lines[i + 2].contains(*c))
            .unwrap();

        sum += score(badge) as u32;
    }
    println!("Task 2: Sum of badges {}", sum);
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("Usage: {} task[1,2] < input", args[0]);
        return;
    }

    let task = &args[1];
    if task == "task1" {
        task1();
    } else if task == "task2" {
        task2();
    } else {
        println!("Invalid task {}", args[1]);
    }
}
