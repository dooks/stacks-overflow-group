#pragma once
#include <iostream>
#include <string>
using namespace std;

class date {
  int m_month;
  int m_day;
  int m_year;

public:
  date();
  date(int, int, int); // Initialize with MM-DD-YYYY format

  // Mutators
  void setMonth(int);
  void setDay(int);
  void setYear(int);
  void operator=(const date& op);
  friend ostream& operator<<(ostream&, date&);

  // Accessors
  int getMonth();
  int getDay();
  int getYear();
  std::string str(); // Returns MM-DD-YYYY

  // Comparison Operators
  bool operator==(const date& op);
  bool  operator<(const date& op);
  bool operator<=(const date& op);
  bool  operator>(const date& op);
  bool operator>=(const date& op);
  bool operator!=(const date& op);
};
