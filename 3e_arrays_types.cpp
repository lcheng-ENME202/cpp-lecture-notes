// ENME 202
// 3e_arrays_types.cpp
// Array data types

#include <iostream>
#include <string>   // library for string objects

using namespace std;

int main(void) {

  // Arrays can contain any valid C++ data type.
  
  // Here is an example for an array of "char" values (single
  // characters):
  cout << endl;
  char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
  for (int i = 0; i < 5; i++) {
    cout << vowels[i] << " ";
  }
  cout << endl << endl;

  // Boolean array:
  bool yesno[4] = {true, false, true, true};
  for (int i = 0; i < 4; i++) {
    cout << yesno[i] << " ";
  }
  cout << endl << endl;

  // Here is aother example, using the string library 
  // (see the 2nd include file at the top of the code):
  string colors[3] = {"Red", "Green", "Blue"};
  for (int i = 0; i < 3; i++) {
    cout << colors[i] << " ";
  }
  cout << endl << endl;

  // Arrays can hold any data type, including programmer-defined
  // data type (structs and objects, which we will discuss soon).

  return 0;
}
