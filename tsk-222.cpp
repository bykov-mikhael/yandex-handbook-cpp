
#include <iostream>

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  std::uint64_t n;

  std::cin >> n;

  if (n < 0) {
    n = 0;
  }

  std::cout << n * (1 + n) / 2 << "\n";

  return EXIT_SUCCESS;
}
