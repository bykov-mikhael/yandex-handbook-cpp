#include <algorithm>
#include <cctype>
#include <iostream>

/**
 * Известный алгоритм Soundex определяет, похожи ли два английских слова по
 * вучанию. На вход он принимает слово и заменяет его на некоторый
 * четырёхсимвольный код. Если коды двух слов совпадают, то слова, как правило,
 * звучат похоже.
 * Вам требуется реализовать этот алгоритм. Он работает так:
 * Первая буква слова сохраняется.
 * В остальной части слова буквы a, e, h, i, o, u, w и y удаляются;
 * Оставшиеся буквы заменяются на цифры от 1 до 6, причём похожим по звучанию
 * буквам соответствуют одинаковые цифры: b, f, p, v: 1 c, g, j, k, q, s, x, z:
 * 2
 * d, t: 3
 * l: 4
 * m, n: 5
 * r: 6
 * Любая последовательность идущих подряд одинаковых цифр сокращается до одной
 * такой цифры. Итоговая строка обрезается до первых четырёх символов. Если
 * длина
 * строки получилась меньше четырёх символов, в конце добавляются нули. Примеры:
 * ammonium → ammnm → a5555 → a5 → a500.
 * implementation → implmnttn → i51455335 → i514535 → i514.
 */

struct answer {
  std::string convert(std::string& string) { return {}; };
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  std::string string{""};

  std::cout << "input string: ";

  std::getline(std::cin, string);

  // std::source_location location = std::source_location::current();

  // std::cout << location.file_name() << std::endl;

  // std::cout << location.line() << std::endl;

  // std::cout << location.function_name() << std::endl;

  return EXIT_SUCCESS;
}
