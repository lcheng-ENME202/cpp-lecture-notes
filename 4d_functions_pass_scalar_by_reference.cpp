// ENME 202
// Functions - passing scalar variables by reference

#include <iostream>
using namespace std;

void swap_by_value(float,float);

void swap_by_reference(float&, float&);
//                         ^^^     ^^^
// The ampersand after the type identifier
// in the input to a function forces C++ to pass
// a reference (i.e. a memory location) for a given
// variable


int main(void) {

  float a,b;

  cout << "Enter values for a and b: ";
  cin >> a >> b;

  // Try swapping a and b using swap_by_value():
  cout << endl << "SWAP BY VALUE:" << endl;
  cout << "Before: a=" << a << " and b=" << b << endl;
  swap_by_value(a,b);
  cout << "After: a=" << a << " and b=" << b << "\n\n";

  // Now swap a and b using swap_by_reference():
  cout << endl << "SWAP BY REFERENCE:" << endl;
  cout << "Before: a=" << a << " and b=" << b << endl;
  swap_by_reference(a,b);
  cout << "After: a=" << a << " and b=" << b << endl;

  return 0;

}



void swap_by_value(float x, float y) {
  float temp;
  temp = x; 
  x = y;
  y = temp;
  // x and y in swap_by_value() are "local" to 
  // this function. They have their own memory addresses,
  // separate from the corresponding variables in main.
  // Thus, switching x and y around DOES NOT CHANGE  
  // variables a and b in main, since those are stored 
  // in different memory addresses from swap's variables
}


void swap_by_reference(float& x, float& y) {
  float temp;
  temp = x;
  x = y;
  y = temp;
  // Arguments are passed by reference, so local variables
  // x and y are assigned to the same memory locations as
  // a and b in main().
  // Since x and y are references to a and b in main(),
  // changes to x and y are also made to a and b in main().
}

