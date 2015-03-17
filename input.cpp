#include <iostream>
using std::cin;

#include "input.h"

char Input::getCh() {
  char retval = cin.get();
  return retval;
}