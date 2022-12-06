use std::io::{self, Read};

fn main() {
    // Read stdin
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    // Split input into different fields
    let (rest, instruction_str) = input.split_once("\n\n").unwrap();
    let (stacks, indices) = rest.rsplit_once("\n").unwrap();

    // Define our crates
    let nbr_of_crates = indices.split_ascii_whitespace().count();
    let mut crates: Vec<Vec<char>> = vec![vec![]; nbr_of_crates];

    // read creates
    for line in stacks.lines().rev() {
        for (i, c) in line.chars().enumerate().filter(|(_, c)| c.is_alphabetic()) {
            let idx: usize = i / 4;
            crates[idx].push(c);
        }
    }

    // parse instructions
    let instructions: Vec<Vec<usize>> = instruction_str
        .lines()
        .map(|str| {
            str.split(" ")
                .filter(|c| c.chars().nth(0).unwrap() <= '9')
                .map(|c| c.parse::<usize>().unwrap())
                .collect()
        })
        .collect();

    println!("Instructions {:?}", instructions);

    // task 1
    for instruction in instructions {
        let n = instruction[0];
        let from = instruction[1] - 1;
        let to = instruction[2] - 1;

        for _ in 0..n {
            if let Some(tmp) = crates[from].pop() {
                crates[to].push(tmp);
            }
        }
    }

    let mut result = String::new();
    for stack in crates {
        result.push(*stack.last().unwrap());
    }

    println!("Task 1 - message: '{}'", result);
}
