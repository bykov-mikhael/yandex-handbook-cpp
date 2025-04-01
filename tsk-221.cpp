// C++ program to remove spaces using stringstream

#include <cstdio>
#include <cstdlib>
#include <iostream>

constexpr double k{2.54};

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  double cm;

  std::cin >> cm;

  std::cout << cm / k << std::endl;

  return EXIT_SUCCESS;
}
