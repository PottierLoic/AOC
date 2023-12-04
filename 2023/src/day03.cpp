#include "aoc.hpp"
#include <vector>


void day03(std::vector<std::string> input) {
  int sum = 0;

  int lineAmount = input.size();
  int lineSize = input[0].size();

  for (int y = 0; y < lineAmount; y++) {
    int x = 0;
    while (x < lineSize) {
      while (x < lineSize && !isdigit(input[y][x])) { x++; }
      if (x < lineSize && isdigit(input[y][x])) {
        int startPosition = x;
        while (x < lineSize && isdigit(input[y][x])) { x++; }
        int digitAmount = x - startPosition;

        bool valid = false;
        for (int xx = startPosition; xx <= startPosition + digitAmount - 1; xx++) {
          for (int dy = -1; dy < 2; dy++) {
            for (int dx = -1; dx < 2; dx++) {
              if (valid == true) { continue; }
              if (xx + dx < 0 || xx + dx >= lineSize || y + dy < 0 || y + dy >= lineAmount) { continue; }
              if (dx == 0 && dy == 0) { continue; }
              char character = input[y + dy][xx + dx];
              if (character != '.' && (character < '0' || character > '9')) {
                valid = true;
              }
            }
          }
        }
        if (valid) {
          std::string numberStr = input[y].substr(startPosition, digitAmount);
          int number = std::stoi(numberStr);
          sum += number;
        }
      }
    }
  }

  std::cout << "Sum of valid part is: " << sum << std::endl;
}