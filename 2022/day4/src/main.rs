/*
    Advent of Code 2022 - by Isak Evaldssson
    Day 4: Camp Cleanup
*/

use std::{collections::HashSet, io};

fn main() {
    let mut overlapping_pairs = 0;
    let mut containing_pairs = 0;

    for line in io::stdin().lines() {
        let str = line.unwrap();
        let numbers: Vec<i32> = str.split(['-', ',']).map(|x| x.parse().unwrap()).collect();
        let t1: HashSet<i32> = HashSet::from_iter(numbers[0]..numbers[1] + 1);
        let t2: HashSet<i32> = HashSet::from_iter(numbers[2]..numbers[3] + 1);

        if t1.intersection(&t2).count() > 0 {
            overlapping_pairs += 1;

            if t1.is_subset(&t2) || t2.is_subset(&t1) {
                containing_pairs += 1;
            }
        }
    }

    println!(
        "Task 1: Number of fully contained assignment pairs {}\n\
         Task 2: Number of overlapping pairs {}",
        containing_pairs, overlapping_pairs
    );
}
