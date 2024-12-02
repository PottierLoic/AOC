#include "aoc.hpp"
#include <unordered_map>

struct Gear {
  int nb;
  std::vector<int> values;
};

int getIndex(int x, int y) {
  return x + y * 140;
}

void day03(std::vector<std::string> input) {
  int sum = 0;

  int lineAmount = input.size();
  int lineSize = input[0].size();

  std::unordered_map<int, Gear> gears;

  for (int y = 0; y < lineAmount; y++) {
    int x = 0;
    while (x < lineSize) {
      while (x < lineSize && !isdigit(input[y][x])) { x++; }
      if (x < lineSize && isdigit(input[y][x])) {
        int startPosition = x;
        while (x < lineSize && isdigit(input[y][x])) { x++; }
        int digitAmount = x - startPosition;
        std::string numberStr = input[y].substr(startPosition, digitAmount);
        int number = std::stoi(numberStr);

        bool valid = false;
        bool hasGear = false;
        for (int xx = startPosition; xx <= startPosition + digitAmount - 1; xx++) {
          for (int dy = -1; dy < 2; dy++) {
            for (int dx = -1; dx < 2; dx++) {
              if (valid == true) { continue; }
              if (xx + dx < 0 || xx + dx >= lineSize || y + dy < 0 || y + dy >= lineAmount) { continue; }
              if (dx == 0 && dy == 0) { continue; }
              char character = input[y + dy][xx + dx];

              if (!hasGear && character == '*') {
                int index = getIndex(xx + dx, y + dy);
                if (gears.find(index) == gears.end()) {
                  Gear newGear;
                  newGear.values.push_back(number);
                  newGear.nb = 1;
                  gears[index] = newGear;
                } else {
                  gears[index].values.push_back(number);
                  gears[index].nb++;
                }
                hasGear = true;
              }
              if (character != '.' && (character < '0' || character > '9')) {
                valid = true;
              }
            }
          }
        }
        if (valid) {
          sum += number;
        }
      }
    }
  }

  std::cout << "Sum of valid part is: " << sum << std::endl;

  int sum2 = 0;
  for (const auto& [index, gear] : gears) {
    if (gear.nb == 2) {
      sum2 += (gear.values[0] * gear.values[1]);
    }
  }
  std::cout << "Sum of gear ratios is: " << sum2 << std::endl;
}