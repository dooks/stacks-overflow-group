#include <iostream>
using std::cin;

#include "input.h"

char Input::getCh() {
  char retval = cin.get();
  return retval;
}

string Input::getLine() {
  string retval;
  getLine(cin, retval);
  return retval;
}