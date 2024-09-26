// ENME 202
// 3b_array_initializing.cpp
// Initializng C++ Arrays

#include <iostream>
using namespace std;

int main(void) {

  // Arrays can be initialized when declared by listing the value of 
  // each element inside curly braces.  Missing values are replaced
  // by zeros:
 
  float v1[3] = {8.6, -3, 1} ;
  float v2[4] = {-1, 2}; // v2[2] and v2[3] default to 0 here
  float v3[9] = {} ;     // v3[0] set to 4, the rest set by default to 0

  cout << "Initial values of v1 = ";
  for (int i=0; i<3; i++) cout << v1[i] << ", ";  // comma separation
  cout << endl << endl;

  cout << "Initial values of v2 = " << endl;
  for (int i=0; i<4; i++) cout << v2[i] << endl;  // endl separation
  cout << endl;

  cout << "Initial values of v3 = ";
  for (int i=0; i<9; i++) cout << v3[i] << " ";   // space separation
  cout << endl << endl;
  
  // Note: you can only use the brace method above to "load" values
  // into an array when it is FIRST declared.  You CANNOT
  // use this technique anywhere in your code after the initial
  // declaration.  You also CANNOT "redeclare" arrays (or any other kind
  // of variable) to take advantage of the initialization syntax:
  // variables in a C++ program can be declared only once!
  
  // Remember that the only way to display the contents of 
  // the entire array is to write each element separately
  // to the screen (as in the loops above).
  // In particular, the below lines will NOT display the
  // array values:

  cout << "v1 = " << v1 << endl;
  cout << "v2 = " << v2 << endl;
  
  // What DID get printed there???
  // 
  // Answer: the base memory addresses for v1 and v2.
  // Keep this in mind when we start talking about dynamic memory
  // allocation, pointers, and dereferencing

  return 0;
}
