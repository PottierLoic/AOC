#include "aoc.hpp"

std::string readInputFromFile(const std::string& filePath) {
  std::ifstream inputFile(filePath);
  if (!inputFile.is_open()) {
    std::cerr << "Error opening file: " << filePath << std::endl;
    return "";
  }

  std::string input;
  std::getline(inputFile, input);

  inputFile.close();
  return input;
}

int main() {
  std::cout << "Starting 2023 Advent of Code !" << std::endl;

  std::string content = readInputFromFile(INPUTS[0]);

  // for (auto& func : functionPointers) {
  //   std::string argument = "Argument for " + std::to_string(&func);
  //   func(argument);
  // }
}