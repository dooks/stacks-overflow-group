#pragma once
#include <string>

class date {
  int m_month;
  int m_day;
  int m_year;

public:
  // Mutators
  void setMonth(int);
  void setDay(int);
  void setYear(int);

  // Accessors
  int getMonth();
  int getDay();
  int getYear();
  std::string str(); // Returns MM-DD-YY

  // Comparison Operators
  bool operator==(const date& op);
  bool  operator<(const date& op);
  bool operator<=(const date& op);
  bool  operator>(const date& op);
  bool operator>=(const date& op);
};