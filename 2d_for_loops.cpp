// ENME 202
// 2d_for_loops.cpp
// for() loops

#include <cmath>
#include <iostream>

using namespace std;

int main(void) {

  // Below is a simple for() loop.
  // j is the loop variable, initialized to 1 (j=1), and
  // incremented by 1 (j++) each time through the loop.
  // The loop keeps running while j remains less than
  // or equal to 5 (j<=5)

  int j;
  for (j=1; j<=5; j++) { 
    cout << "j = " << j << endl;
  }

  // Note that initializing, testing, and incrementing
  // the loop variable all must be done manually in 
  // C++.  The three statements in parentheses after "for",
  // separated by semicolons, respectively specify each step

  // The loop variable can be declared outside or inside the loop.
  // If it is declared inside the loop, its scope is within the loop
  // only, and is thus not defined outside the loop!
  
  for (int i=0; i<5; i++) {
    cout << "i = " << i << endl;
  }

  // The loop variable does not need to be an integer.
  // Here is an example with a float as the loop variable
  // to print out powers of 2 in a specified range:

  float kmin = -2.1, kmax = 1.55, kinc = 0.5;
  cout << endl << "Powers of 2 from " << kmin << " to " << kmax;
  cout << " in increments of " << kinc << " are:" << endl;

  for (float k=kmin; k<=kmax; k+=kinc) { // or k*=kinc, etc; 
    cout << "2^(" << k << ") = " << pow(2.0,k) << endl;
  }

  return 0;
}