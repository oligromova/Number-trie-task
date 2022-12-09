#include "number.h"

number_t::number_t() : m_number{0} {}

number_t::number_t(const number_t &other) : m_number{other.m_number} {}

number_t::number_t(int64_t other) : m_number{other} {}

number_t::~number_t() = default;

number_t::operator bool() const {
  return !!m_number;
}

number_t::operator int64_t() const {
  return m_number;
}

number_t::operator std::string() const {
  return std::to_string(m_number);
}

number_t& number_t::operator=(number_t other) {
    m_number = other.m_number;
    return *this;
}

number_t operator+(number_t left, number_t right) {
  return number_t{left.m_number + right.m_number};
}
number_t &number_t::operator+=(number_t other) {
  m_number += other.m_number;
  return *this;
}

number_t operator-(number_t left, number_t right) {
  return number_t{left.m_number - right.m_number};
}
number_t &number_t::operator-=(number_t other) {
  m_number -= other.m_number;
  return *this;
}

number_t operator*(number_t left, number_t right) {
  return number_t{left.m_number * right.m_number};
}
number_t &number_t::operator*=(number_t other) {
  m_number *= other.m_number;
  return *this;
}

number_t operator/(number_t left, number_t right) {
  return number_t{left.m_number / right.m_number};
}
number_t &number_t::operator/=(number_t other) {
  m_number /= other.m_number;
  return *this;
}

number_t operator%(number_t left, number_t right) {
  return number_t{left.m_number % right.m_number};
}
number_t &number_t::operator%=(number_t other) {
  m_number %= other.m_number;
  return *this;
}

number_t operator&(number_t left, number_t right) {
  return number_t{left.m_number & right.m_number};
}
number_t &number_t::operator&=(number_t other) {
  m_number &= other.m_number;
  return *this;
}

number_t operator|(number_t left, number_t right) {
  return number_t{left.m_number | right.m_number};
}
number_t &number_t::operator|=(number_t other) {
  m_number |= other.m_number;
  return *this;
}

number_t operator^(number_t left, number_t right) {
  return number_t{left.m_number ^ right.m_number};
}
number_t &number_t::operator^=(number_t other) {
  m_number ^= other.m_number;
  return *this;
}

number_t number_t::operator~() const {
  return number_t{~m_number};
}

number_t operator>>(number_t left, number_t right) {
  return number_t{left.m_number >> right.m_number};
}
number_t &number_t::operator>>=(uint8_t shift) {
  m_number >>= shift;
  return *this;
}

number_t operator<<(number_t left, number_t right) {
  return number_t{left.m_number << right.m_number};
}
number_t &number_t::operator<<=(uint8_t shift) {
  m_number <<= shift;
  return *this;
}

number_t number_t::operator+() const {
  return *this;
}

number_t number_t::operator-() const {
  return number_t{-m_number};
}

number_t &number_t::operator++() {
  m_number++;
  return *this;
}
number_t number_t::operator++(int) {
  number_t num{m_number};
  m_number++;
  return num;
}

number_t &number_t::operator--() {
  m_number--;
  return *this;
}
number_t number_t::operator--(int) {
  number_t num{m_number};
  m_number--;
  return num;
}

bool operator<(number_t left, number_t right) {
  return left.m_number < right.m_number;
}

bool operator>(number_t left, number_t right) {
  return left.m_number > right.m_number;
}

bool operator<=(number_t left, number_t right) {
  return left.m_number <= right.m_number;
}

bool operator>=(number_t left, number_t right) {
  return left.m_number >= right.m_number;
}

bool operator==(number_t left, number_t right) {
  return left.m_number == right.m_number;
}

bool operator!=(number_t left, number_t right) {
  return left.m_number != right.m_number;
}

std::ostream &operator<<(std::ostream &out, number_t &num) {
  out << num.m_number;
  return out;
}

std::istream &operator>>(std::istream &in, number_t &num) {
  in >> num.m_number;
  return in;
}
