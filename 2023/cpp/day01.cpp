#include "aoc.hpp"
#include <numeric>
#include <algorithm>

const std::vector<std::string> NUMBERS = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void day01(std::vector<std::string> input) {
  std::vector<int> values;
  for (const std::string& line : input) {
    std::vector<int> digits;
    size_t idx = 0;
    for (const char& c : line) {
      if ('0' <= c && c <= '9') {
        digits.push_back(c - '0');
      } else {
        auto it = std::find_if(std::begin(NUMBERS), std::end(NUMBERS), [&](const std::string& num) { return line.compare(idx, num.size(), num) == 0; });
        if (it != std::end(NUMBERS)) {
          digits.push_back(std::distance(std::begin(NUMBERS), it) + 1);
        }
      }
      idx++;
    }
    values.push_back(digits.front() * 10 + digits.back());
  }
  std::cout << std::accumulate(std::begin(values), std::end(values), 0) << std::endl;
}