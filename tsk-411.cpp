#include <algorithm>
#include <cstddef>
#include <functional>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

/**
 * Вам надо написать класс Date для хранения даты григорианского календаря.
 * 1. Используйте три переменных типа int для хранения дня, месяца и года
 * 2. В вашем классе должен быть следующий публичный интерфейс:
 * 2.1 Конструктор, принимающий на вход три числа: день, месяц и год. В случае
 * некорректной даты должна создаваться дата: 1 января 1970
 * 2.2 Константные функции GetDay, GetMonth и GetYear.
 * 2.3 Бинарные операторы + и -, где вторым аргументом является целое число —
 * количество дней. Эти операторы должны вернуть новую дату, отстоящую от
 * заданной на указанное число дней. Бинарный оператор -, вычисляющий разность
 * между двумя датами и возвращающий int – количество дней. Считайте, что все
 * обрабатываемые даты будут лежать в пределах между:
 * 1 января 1970 и 31 декабря 2099
 */

#include <iostream>
#include <stdexcept>

namespace Date {

//начальные дата, месяц, год
constexpr int begin_day{1};
constexpr int begin_month{1};
constexpr int begin_year{1970};

//конечныные дата, месяц, год
constexpr int end_day{31};
constexpr int end_month{12};
constexpr int end_year{2099};

class Date {
 public:
  Date(int day, int month, int year)
      : m_day{day}, m_month{month}, m_year{year} {
    if (day > 31) throw std::out_of_range("wrong date");

    if (month > 12) throw std::out_of_range("wrong month");

    if (year > 9999) throw std::out_of_range("wrong year");
  };

  // TODO! добавить конструктор копирования

  // TODO! добавить конструктор перемещения

  int GetDate() const { return m_day; }

  int GetMonth() const { return m_month; }

  int GetYear() const { return m_year; }

  Date operator+(const Date &date) const {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Date{m_day + date.m_day, m_month, m_year};
  }

  template <int T>
  Date operator+(int date) {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Date(m_day + date, m_month, m_year);
  }

  template <typename T>
  Date operator-(const T &date) const {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return Date{date};
  }

  int operator-(const Date &date) const {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    return m_day - date.m_day;
  }

  void show() {
    std::cout << __PRETTY_FUNCTION__ << std::endl;
    std::cout << GetDate() << "/" << GetMonth() << "/" << GetYear()
              << std::endl;
  };

 private:
  int m_day{1};
  int m_month{1};
  int m_year{1970};

  /**
   * @brief Високосный год — это особый год, в котором февраль имеет 29 дней
   * вместо обычных 28. Это происходит каждые 4 года, за исключением тех
   * годов, которые делятся на 100, но не делятся на 400. Другими словами,
   * если год делится на 4, но не делится на 100, то это високосный год. Если
   * год делится на 400, то он тоже високосный. Например, 2000 год високосный,
   * а 1900 — нет.
   *
   * @param date структура для определения вискосного года
   * @return true высокосный год
   * @return false не високосный год
   */
  bool isLeapYear() const {
    return (m_year % 4 == 0 && m_year % 100 != 0) || (m_year % 400 == 0);
  }
};
}  // namespace Date

int main() {
  Date::Date date001{1, 1, 1980};
  Date::Date date002{1, 1, 1990};
  Date::Date date003{1, 1, 2000};

  date003 = date001 + date002;

  date003.show();

  date003 = date001 + 10;
  date003.show();

  auto *date011 = new Date::Date{1, 1, 1980};
  auto rdate011 = *date011;
  auto *date012 = new Date::Date{2, 1, 1990};
  auto rdate012 = *date012;
  auto *date013 = new Date::Date{3, 1, 2000};
  auto rdate013 = *date013;

  rdate013 = rdate011 + rdate012;

  date013->show();

  int diffDay{rdate013 - rdate012};

  std::cout << diffDay << std::endl;
}
