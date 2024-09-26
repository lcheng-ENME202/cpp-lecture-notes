// ENME 202
// 2e_switch_case.cpp
// switch() / case statements

#include <iostream>

using namespace std;

int main(void) {

  // The switch statement allows us to control when the code within
  // the code block will be entered.  All code in the cases after
  // entry will also be executed.  This is a fundamental difference
  // from the way switch works in Matlab, where ONLY code from
  // the matching case is executed.

  int i;
  cout << "Enter an integer: ";
  cin >> i;

  switch (i) {
    case -1: cout << "-1 \n";
    case 0: cout << "the value is 0 \n";
    case 1: cout << "the value is 1 \n";    // execution starts here
    case 2:
      cout << "the value is 2 ... now break \n";
      break;                   // break out of the switch code block
    case 3: cout << "the value is 3 \n";
    case 4: cout << "the value is 4 \n";
    default:                   // do this unless "break" called when i==2
      cout << "this is the default block ";
      cout << "that will always execute unless a break occurs";
  }

  return 0;
}
