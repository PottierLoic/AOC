#include "aoc.hpp"
#include <vector>
#include <string>
#include <sstream>

struct ColorValue {
  std::string color;
  int value;
};

std::vector<ColorValue> extractColorValues(const std::string& line) {
  std::vector<ColorValue> colorValues;

  std::istringstream ss(line);
  std::string colorValueStr;

  while (std::getline(ss, colorValueStr, ';')) {
    size_t start = colorValueStr.find_first_not_of(" \t\n\r\f\v");
    size_t end = colorValueStr.find_last_not_of(" \t\n\r\f\v");
    colorValueStr = colorValueStr.substr(start, end - start + 1);

    std::istringstream colorValueStream(colorValueStr);
    std::string color;
    int value;

    while (colorValueStream >> value >> color) {
      size_t commaPos = color.find(',');
      color = color.substr(0, commaPos);
      colorValues.push_back({color, value});
    }
  }

  return colorValues;
}

int extractGameID(const std::string& line) {
  size_t colonPos = line.find(':');
  std::string gameIDString = line.substr(5, colonPos - 5);
  return stoi(gameIDString);
}

void day02(std::vector<std::string> input) {
  std::vector<int> colors = {12, 13, 14};
  int sum = 0;
  int cubeSetSum = 0;

  for (const std::string& game : input) {
    int gameID = extractGameID(game);
    std::string cleanedLine = game.substr(game.find(':') + 2);
    std::vector<ColorValue> colorValues = extractColorValues(cleanedLine);

    bool valid = true;
    int red = 0;
    int green = 0;
    int blue = 0;
    for (const ColorValue& cv : colorValues) {
      if (cv.color == "red") {
        if (valid) { valid = cv.value <= colors[0]; }
        if (cv.value > red) { red = cv.value; }
      }
      else if (cv.color == "green") {
        if (valid) { valid = cv.value <= colors[1]; }
        if (cv.value > green) { green = cv.value; }
      }
      else if (cv.color == "blue") {
        if (valid) { valid = cv.value <= colors[2]; }
        if (cv.value > blue) { blue = cv.value; }
      }
    }

    cubeSetSum += red * green * blue;

    if (valid) {
      sum += gameID;
    }
  }

  std::cout << "Sum is: " << sum << std::endl;
  std::cout << "CubeSet Power Sum is: " << cubeSetSum << std::endl;
}