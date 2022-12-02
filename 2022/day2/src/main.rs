/*
    Advent of Code 2022 - by Isak Evaldssson
    Day 2: Rock Paper Scissors
*/

use std::{env, io};

// Score depending on outcome
const ROCK: i32 = 1;
const PAPER: i32 = 2;
const SCISSORS: i32 = 3;

#[derive(Debug)]
enum Outcome {
    Win,
    Loss,
    Draw,
}

fn parse_opponent(input: &str) -> i32 {
    match input {
        "A" => ROCK,
        "B" => PAPER,
        "C" => SCISSORS,
        _ => 0,
    }
}

fn task1() {
    let mut total_score = 0;

    for line in io::stdin().lines() {
        let str = line.unwrap();
        let round: Vec<&str> = str.split(" ").collect();

        let opponent_move = parse_opponent(round[0]);
        let your_move = match round[1] {
            "X" => ROCK,
            "Y" => PAPER,
            "Z" => SCISSORS,
            _ => 0,
        };

        // Game
        let score = if (your_move == ROCK && opponent_move == SCISSORS)
            || (your_move == SCISSORS && opponent_move == PAPER)
            || (your_move == PAPER && opponent_move == ROCK)
        {
            6
        } else if your_move == opponent_move {
            3
        } else {
            0 // Loss
        } + your_move;

        total_score += score;
    }

    println!("Task 1: Total score: {}", total_score);
}

fn task2() {
    let mut total_score = 0;

    for line in io::stdin().lines() {
        let str = line.unwrap();
        let round: Vec<&str> = str.split(" ").collect();

        let opponent_move = parse_opponent(round[0]);
        let expected_outcome = match round[1] {
            "Y" => Outcome::Draw,
            "X" => Outcome::Loss,
            _ => Outcome::Win,
        };

        // Game
        let score: i32 = match expected_outcome {
            Outcome::Win => {
                6 + match opponent_move {
                    ROCK => PAPER,
                    PAPER => SCISSORS,
                    SCISSORS => ROCK,
                    _ => 0,
                }
            }
            Outcome::Loss => {
                0 + match opponent_move {
                    ROCK => SCISSORS,
                    PAPER => ROCK,
                    SCISSORS => PAPER,
                    _ => 0,
                }
            }
            Outcome::Draw => 3 + opponent_move,
        };

        total_score += score;
    }

    println!("Task 2: Total score: {}", total_score);
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
