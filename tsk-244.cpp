#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

/**
 * Вам даны строки текстового файла. Отсортируйте набор этих строк по убыванию.
 * Формат ввода
 * Количество строк не превосходит 1000. Каждая строка состоит из символов ASCII
 * с кодами от 32 до 126, длина строки не превосходит 100.
 * Формат вывода
 * Напечатайте строки в отсортированном по убыванию порядке. Для сравнения строк
 * друг с другом достаточно использовать стандартные операторы сравнения,
 * определённые для std::string.
 * Пример
 * Ввод:
 * one
 * two
 * three
 * Вывод:
 * two
 * three
 * one
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> lines;

  std::string line;
  while (std::getline(std::cin, line)) {
    lines.push_back(line);
  }

  std::sort(lines.rbegin(), lines.rend());

  for (size_t i = 0; i != lines.size(); ++i) {
    std::cout << lines[i] << "\n";
  }
}
