use std::{io, vec};

fn main() {
    let mut elf = 0;
    let mut calories: Vec<i32> = vec![0];

    for line in io::stdin().lines() {
        let str = line.unwrap();

        if str.is_empty() {
            elf += 1;
            calories.push(0);
            continue;
        }

        calories[elf] += str.parse::<i32>().unwrap();
    }

    // Part 1
    println!("Part 1: Max value: {}", calories.iter().max().unwrap());

    // Part 2
    calories.sort();
    println!(
        "Part 2: Sum of top 3 values: {}",
        calories[elf - 2..elf + 1].iter().sum::<i32>()
    );
}
