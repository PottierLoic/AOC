#include "aoc.hpp"

std::vector<std::string> readInputFromFile(const std::string& filePath) {
  std::ifstream inputFile(filePath);
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file: " << filePath << std::endl;
    return {};
  }

  std::vector<std::string> lines;
  std::string line;
  while (std::getline(inputFile, line)) {
    lines.push_back(line);
  }

  inputFile.close();
  return lines;
}

int main() {
  std::cout << "Starting 2023 Advent of Code !" << std::endl;

  for (std::size_t i = 0; i < FUNCTIONS_PTR.size(); ++i) {
    FUNCTIONS_PTR[i](readInputFromFile(INPUTS[i]));
  }

  return 0;
}