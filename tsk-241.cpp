#include <algorithm>
#include <cctype>
#include <ios>
#include <iostream>
#include <iterator>
// #include <source_location>

/**
 * Пароль от некоторого сервиса должен удовлетворять таким ограничениям:
 * - состоять из символов таблицы ASCII с кодами от 33 до 126;
 * - быть не короче 8 символов и не длиннее 14;
 * - из 4 классов символов — большие буквы, маленькие буквы, цифры, прочие -
 * символы — в пароле должны присутствовать не менее трёх любых.
 */

constexpr int min_length{8};
constexpr int max_length{14};
constexpr int min_ch_code{33};
constexpr int max_ch_code{126};
constexpr int SYMBOLS_COUNT{3};

struct answer {
  bool password(std::string& password) {
    /*
     * - состоять из символов таблицы ASCII с кодами от 33 до 126;
     */
    int numCode = std::ranges::count_if(
        password.begin(), password.end(), [&numCode](auto ch) {
          if ((static_cast<int>(ch) > min_ch_code) ||
              (static_cast<int>(ch) < max_ch_code)) {
            numCode++;
          }
          return numCode;
        });

    /*
     * - быть не короче 8 символов и не длиннее 14;
     */
    if ((password.length() < min_length) || (password.length() > max_length)) {
      std::cout << "incorrect length password" << std::endl;
      return false;
    } else {
      std::cout << "correct length password" << std::endl;
    }
    /*
     * - из 4 классов символов — большие буквы, маленькие буквы, цифры, прочие -
     * символы — в пароле должны присутствовать не менее трёх любых.
     */
    int numUpper =
        std::ranges::count_if(password.begin(), password.end(), isupper);

    std::cout << "numUpper " << numUpper << std::endl;

    int numLower =
        std::ranges::count_if(password.begin(), password.end(), islower);

    std::cout << "numLower " << numLower << std::endl;

    int numDigit =
        std::ranges::count_if(password.begin(), password.end(), isdigit);

    std::cout << "numDigit " << numDigit << std::endl;

    if ((numUpper + numLower + numDigit) < SYMBOLS_COUNT) {
      std::cout << "incorrect symbol count " << std::endl;
      return false;
    }

    return true;
  };
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char* argv[]) {
  std::string passwd{""};
  answer ans;

  std::cout << "password check: ";

  std::getline(std::cin, passwd);

  std::cout << std::boolalpha << ans.password(passwd) << std::endl;

  // std::source_location location = std::source_location::current();

  // std::cout << location.file_name() << std::endl;

  // std::cout << location.line() << std::endl;

  // std::cout << location.function_name() << std::endl;

  return EXIT_SUCCESS;
}
