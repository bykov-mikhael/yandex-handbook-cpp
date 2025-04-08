#include <iostream>
#include <string>

/**
 * Известный алгоритм Soundex определяет, похожи ли два английских слова по
 * вучанию. На вход он принимает слово и заменяет его на некоторый
 * четырёхсимвольный код. Если коды двух слов совпадают, то слова, как правило,
 * звучат похоже.
 * Вам требуется реализовать этот алгоритм. Он работает так:
 * 1 - Первая буква слова сохраняется.
 * 2. В остальной части слова буквы a, e, h, i, o, u, w и y удаляются;
 * Оставшиеся буквы заменяются на цифры от 1 до 6, причём похожим по звучанию
 * буквам соответствуют одинаковые цифры:
 * b, f, p, v: 1
 * c, g, j, k, q, s, x, z: 2
 * d, t: 3
 * l: 4
 * m, n: 5
 * r: 6
 * 3. Любая последовательность идущих подряд одинаковых цифр сокращается до
 * одной такой цифры Итоговая строка обрезается до первых четырёх символов
 * Если длина строки получилась меньше четырёх символов, в конце добавляются
 * нули
 * Примеры:
 * ammonium → ammnm → a5555 → a5 → a500.
 * implementation → implmnttn → i51455335 → i514535 → i514.
 */

struct answer {
  std::string append(std::string& string, char code) {
    /**
     * @brief если последний символ строки - string не совпадает с символом -
     * code, тогда добавляется числовой код - code, иначе ничего не происходит
     */
    if (!string.ends_with(code)) {
      string.push_back(code);
    }
    return string;
  }

  std::string convert(std::string& string) {
    std::string str{};

    str.push_back(string[0]);

    for (size_t pos = 1; pos != string.size(); pos++) {
      switch (string[pos]) {
        case 'b':
        case 'f':
        case 'p':
        case 'v':
          append(str, '1');
          break;
        case 'c':
        case 'g':
        case 'j':
        case 'k':
        case 'q':
        case 's':
        case 'x':
        case 'z':
          append(str, '2');
          break;
        case 'd':
        case 't':
          append(str, '3');
          break;
        case 'l':
          append(str, '4');
          break;
        case 'm':
        case 'n':
          append(str, '5');
          break;
        case 'r':
          append(str, '6');
          break;
        default:
          break;
      }
    }

    while (str.size() < 4) {
      str.push_back('0');
    }

    str.resize(4);

    return str;
  }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  answer ans;
  std::string string{""};

  std::cout << "input string: ";

  std::getline(std::cin, string);

  std::cout << ans.convert(string) << std::endl;

  return EXIT_SUCCESS;
}
