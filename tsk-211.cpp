// C++ program to remove spaces using stringstream

#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  std::ifstream input("tsk-221.txt");

  std::string str;

  while (std::getline(input, str)) {
    std::cout << str << std::endl;
  }

  return EXIT_SUCCESS;
}
