#include "date.h"
using std::string;

// Constructors
date::date() : m_month(0), m_day(0), m_year(0) { }

date::date(int mm, int dd, int yyyy) : // Initialize with MM-DD-YYYY format
  m_month(mm), m_day(dd), m_year(yyyy) { }

// Mutators
void date::setMonth(int month) { m_month = month; }
void   date::setDay(int   day) {   m_day =   day; }
void  date::setYear(int  year) {  m_year =  year; }
void date::operator=(const date& op) {
  m_month = op.m_month;
    m_day = op.m_day;
   m_year = op.m_year;
}

// Accessors
int date::getMonth() { return m_month; }
int   date::getDay() {   return m_day; }
int  date::getYear() {  return m_year; }
string date::str() {
  string d = ""; // Create temp string
  d += m_month;
  d += "/" + m_day;
  d += "/" + m_year; // Serialize date into string
  return d;
}

// Comparison operators
bool date::operator==(const date& op) {
  // If years are equal
  //    If months are equal
  //      If days are equal
  //        return true
  // else return false

  if(m_year == op.m_year) {
    if(m_month == op.m_month) {
      if(m_day == op.m_day) {
        return true;
      }
    }
  }

  return false;
}
bool  date::operator<(const date& op) {
  // If other's year is less than or equal to year
  //    If other's months is less than or equal to month
  //      If other's days is less than day
  //        return true
  // else return false

  if(m_year <= op.m_year) {
    if(m_month <= op.m_month) {
      if(m_day < op.m_day) {
        return true;
      }
    }
  }

  return false;
}

bool date::operator<=(const date& op) {
  // If other's year is less than or equal to year
  //    If other's months is less than or equal to month
  //      If other's days is less than or equal to day
  //        return true
  // else return false

  if(m_year <= op.m_year) {
    if(m_month <= op.m_month) {
      if(m_day <= op.m_day) {
        return true;
      }
    }
  }
  return false;
}

bool  date::operator>(const date& op) {
  // If other's year is greater than or equal to year
  //    If other's months is greater than or equal to month
  //      If other's days is greater than day
  //        return true
  // else return false

  if(m_year >= op.m_year) {
    if(m_month >= op.m_month) {
      if(m_day > op.m_day) {
        return true;
      }
    }
  }
  return false;
}

bool date::operator>=(const date& op) {
  // If other's year is greater than or equal to year
  //    If other's months is greater than or equal to month
  //      If other's days is greater than or equal to day
  //        return true
  // else return false

  if(m_year >= op.m_year) {
    if(m_month >= op.m_month) {
      if(m_day >= op.m_day) {
        return true;
      }
    }
  }
  return false;
}

bool date::operator!=(const date& op) {
  // If other's year is greater than or equal to year
  //    If other's months is greater than or equal to month
  //      If other's days is greater than or equal to day
  //        return true
  // else return false

  if(m_year != op.m_year) {
    if(m_month != op.m_month) {
      if(m_day != op.m_day) {
        return true;
      }
    }
  }

  return false;
}
