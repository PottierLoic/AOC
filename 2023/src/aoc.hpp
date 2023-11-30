#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

// File paths for input files corresponding to each day.
static const std::vector<std::string> INPUTS = {
  "inputs/day01.txt",
  // Add other day's inputs as needed.
};

// Function declarations for each day.
void day01(std::vector<std::string>);
// Declare other days functions as needed.


// Vector of pointer to each day functions
static const std::vector<void (*)(std::vector<std::string>)> FUNCTIONS_PTR = {
  day01, /* Fill with functions as needed. */
};