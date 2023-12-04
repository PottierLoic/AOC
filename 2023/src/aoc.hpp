#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// File paths for input files corresponding to each day.
static const std::vector<std::string> INPUTS = {
  "inputs/day01.txt",
  "inputs/day02.txt",
  "inputs/day03.txt",
  "inputs/day04.txt",
  // Add other day's inputs as needed.
};

// Function declarations for each day.
void day01(std::vector<std::string>);
void day02(std::vector<std::string>);
void day03(std::vector<std::string>);
void day04(std::vector<std::string>);
// Declare other days functions as needed.


// Vector of pointer to each day functions
static const std::vector<void (*)(std::vector<std::string>)> FUNCTIONS_PTR = {
  day01,
  day02,
  day03,
  day04,
  /* Fill with functions as needed. */
};