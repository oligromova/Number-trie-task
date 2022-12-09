#pragma once

#include <cstdint>
#include <iostream>

class number_t {
  int64_t m_number;

public:
  number_t();
  number_t(const number_t &other);
  number_t(int64_t other);

  ~number_t();

  explicit operator bool() const;
  explicit operator int64_t() const;
  explicit operator std::string() const;
  
  number_t& operator=(number_t otehr);

  friend number_t operator+(number_t left, number_t right);
  number_t &operator+=(number_t other);

  friend number_t operator-(number_t left, number_t right);
  number_t &operator-=(number_t other);

  friend number_t operator*(number_t left, number_t right);
  number_t &operator*=(number_t other);

  friend number_t operator/(number_t left, number_t right);
  number_t &operator/=(number_t other);

  friend number_t operator%(number_t left, number_t right);
  number_t &operator%=(number_t other);

  friend number_t operator&(number_t left, number_t right);
  number_t &operator&=(number_t other);

  friend number_t operator|(number_t left, number_t right);
  number_t &operator|=(number_t other);

  friend number_t operator^(number_t left, number_t right);
  number_t &operator^=(number_t other);

  number_t operator~() const;

  friend number_t operator>>(number_t left, number_t right);
  number_t &operator>>=(uint8_t shift);

  friend number_t operator<<(number_t left, number_t right);
  number_t &operator<<=(uint8_t shift);

  number_t operator+() const;
  number_t operator-() const;

  number_t &operator++();
  number_t operator++(int);

  number_t &operator--();
  number_t operator--(int);

  friend bool operator<(number_t left, number_t right);
  friend bool operator>(number_t left, number_t right);
  friend bool operator<=(number_t left, number_t right);
  friend bool operator>=(number_t left, number_t right);
  friend bool operator==(number_t left, number_t right);
  friend bool operator!=(number_t left, number_t right);

  friend std::ostream &operator<<(std::ostream &out, number_t &num);
  friend std::istream &operator>>(std::istream &in, number_t &num);
};
