#include <iostream>
using namespace std;

#include "input.h"

char Input::getCh() {
  char retval;
  cin.get(retval);

  // Check if char is a digit
  if(retval >= 48 && retval <= 57) {
    // If so, subtract 48 to make sure they make sense to the user
    retval -= 48;
  }

  cin.clear(); // Unset fail bits
  cin.sync();

  return retval;
}

string Input::getLine() {
  string retval;
  getline(cin, retval);
  cin.sync();
  return retval;
}
