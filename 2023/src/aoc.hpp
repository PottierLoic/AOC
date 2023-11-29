#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

static const std::vector<std::string> INPUTS = {
  "inputs/day01.txt",
  "inputs/day02.txt",
};

void day01(std::vector<std::string>);
void day02(std::vector<std::string>);
// void day03(std::vector<std::string>);
// void day04(std::vector<std::string>);
// void day05(std::vector<std::string>);
// void day06(std::vector<std::string>);
// void day07(std::vector<std::string>);
// void day08(std::vector<std::string>);
// void day09(std::vector<std::string>);
// void day10(std::vector<std::string>);
// void day11(std::vector<std::string>);
// void day12(std::vector<std::string>);
// void day13(std::vector<std::string>);
// void day14(std::vector<std::string>);
// void day15(std::vector<std::string>);
// void day16(std::vector<std::string>);
// void day17(std::vector<std::string>);
// void day18(std::vector<std::string>);
// void day19(std::vector<std::string>);
// void day20(std::vector<std::string>);
// void day21(std::vector<std::string>);
// void day22(std::vector<std::string>);
// void day23(std::vector<std::string>);
// void day24(std::vector<std::string>);
// void day25(std::vector<std::string>);

static const std::vector<void (*)(std::vector<std::string>)> FUNCTIONS_PTR = {
  day01, day02,
  // day03, day04, day05,
  // day06, day07, day08, day09, day10,
  // day11, day12, day13, day14, day15,
  // day16, day17, day18, day19, day20,
  // day21, day22, day23, day24, day25
};