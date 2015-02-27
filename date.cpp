#include "date.h"
using std::string;

// Mutators
void date::setMonth(int month) { m_month = month; }
void   date::setDay(int   day) {   m_day =   day; }
void  date::setYear(int  year) {  m_year =  year; }

// Accessors
int date::getMonth() { return m_month; }
int   date::getDay() {   return m_day; }
int  date::getYear() {  return m_year; }
string         str() {
  // Create temp string
  // Serialize month/day/year into string
  // return temp string
}

// Comparison operators
bool operator==(const date& op) {
  // If years are equal
  //    If months are equal
  //      If days are equal
  //        return true
  // else return false
}
bool  operator<(const date& op) {
  // If other's year is less than or equal to year
  //    If other's months is less than or equal to month
  //      If other's days is less than day
  //        return true
  // else return false
}

bool operator<=(const date& op) {
  // If other's year is less than or equal to year
  //    If other's months is less than or equal to month
  //      If other's days is less than or equal to day
  //        return true
  // else return false
}

bool  operator>(const date& op) {
  // If other's year is greater than or equal to year
  //    If other's months is greater than or equal to month
  //      If other's days is greater than day
  //        return true
  // else return false
}

bool operator>=(const date& op) {
  // If other's year is greater than or equal to year
  //    If other's months is greater than or equal to month
  //      If other's days is greater than or equal to day
  //        return true
  // else return false
}
