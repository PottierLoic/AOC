use std::fs;
use std::io::{BufRead, BufReader};

fn part_one() {
    let mut pointer = 50;
    let mut zero_count = 0;
    let file_path = "inputs/1";
    let file = fs::File::open(file_path);
    let reader = BufReader::new(file.unwrap());
    for instruction in reader.lines() {
        let instruction = instruction.unwrap();
        let direction = if instruction.chars().next().unwrap() == 'L' {
            -1
        } else {
            1
        };
        let value = instruction[1..].parse::<i32>().unwrap();
        pointer += direction * value;
        pointer = pointer.rem_euclid(100);
        if pointer == 0 {
            zero_count += 1;
        }
    }
    println!("part one : {}", zero_count);
}

fn part_two() {
    let mut pointer: i32 = 50;
    let mut zero_count = 0;
    let file_path = "inputs/1";
    let file = fs::File::open(file_path);
    let reader = BufReader::new(file.unwrap());
    for instruction in reader.lines() {
        let instruction = instruction.unwrap();
        let direction = if instruction.chars().next().unwrap() == 'L' {
            -1
        } else {
            1
        };
        let value = instruction[1..].parse::<i32>().unwrap();
        for _ in 0..value {
            pointer += direction;
            pointer = pointer.rem_euclid(100);
            if pointer == 0 {
                zero_count += 1;
            }
        }
    }
    println!("part two : {}", zero_count);
}

fn main() {
    part_one();
    part_two();
}
