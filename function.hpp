#pragma once

#include <iostream>
#include <string>
#include <vector>

bool solution(std::string const &str, std::string const &ending) {
  std::cout << "str => " << str << std::endl;

  std::cout << "ending => " << ending << std::endl;

  std::cout << "str.find(" << ending << ") =>" << str.rfind(ending)
            << std::endl;

  std::cout << "str.length() =>" << str.length() << std::endl;

  std::cout << "ending.length() =>" << ending.length() << std::endl;

  if (ending.empty()) return true;

  if ((str.rfind(ending) != std::string::npos) &&
      str.find(ending) + ending.length() == str.length())
    return true;

  return false;
}

bool lovefunc(int f1, int f2) {
  bool result;

  ((f1 + f2) % 2 == 0) ? result = false : result = true;

  return result;
}

std::vector<std::string> friendOrFoe(const std::vector<std::string> &input) {
  std::vector<std::string> result;

  for (auto rec : input) {
    if (rec.length() == 4) {
      result.push_back(rec);
    }
  }

  return result;
}