#include "aoc.hpp"
#include <chrono>

/**
 * @brief Reads lines from a file and returns them as a vector of strings.
 *
 * @param filePath The path to the input file.
 * @return A vector of strings containing each line from the file.
 *         If there's an error opening the file, an empty vector is returned.
 */
std::vector<std::string> readInput(const std::string& filePath) {
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

/**
 * Entry point of the program. Executes Advent of Code functions and measures their durations.
 *
 * @return 0 on successful execution.
 */
int main() {
  std::cout << "Starting 2023 Advent of Code !" << std::endl;

  for (std::size_t i = 0; i < FUNCTIONS_PTR.size(); ++i) {
    auto start = std::chrono::high_resolution_clock::now();
    FUNCTIONS_PTR[i](readInput(INPUTS[i]));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Day " << i + 1 << " took " << duration.count() << " milliseconds." << std::endl;
  }

  return 0;
}
