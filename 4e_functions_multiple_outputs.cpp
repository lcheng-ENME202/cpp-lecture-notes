// ENME 202
// 4e_functions_multiple_outputs.cpp
// Functions - returning multiple values

#include <iostream>
#include <cmath> 
using namespace std;

// A C++ function can have at most **ONE** output.
//
// What are the options for getting more than one result
// from a function?  To explore one answer to this question, 
// let's write a max() function that works like the 
// Matlab "max" function, which can tell us both the maximum 
// value stored in an array, AND the index into the array
// the maximum occurs, i.e. [val,idx] = max(v).
//
// We can't achieve the identical syntax in C++, but we do have
// two options to get equivalent behavior, both of which involve
// passing scalar variables by reference

// Option 1:
// Pass variables to hold the max value and index of the max
// by reference.  These variables are changed inside the function.
void max1(float*, int, float&, int&);
//          ^      ^     ^      ^
//          |      |     |      max index to "return"
//          |      |     max value to "return"
//          |      pass # of elements in array
//          pass array pointer

// Option 2:
// Return the max value as a normal output, and pass the index
// by reference for modification within the function.
float max2(float*, int, int&);
// ^         ^      ^    ^
// |         |      |    max index to "return"
// |         |      pass # of elements in array
// |         pass array pointer
// return max value

// Note that in both options, the array and its length are
// the first two inputs to each function

int main(void) {

  int idx1, idx2;
  float val1, val2;
  float v[5] = {0.2, -4.3, 2.8, 8.6, 1.9};

  // Option #1: using the max1 function
  max1(v, 5, val1, idx1);
  cout << "Using max1, max(v) = " << val1;
  cout << " at index " << idx1 << endl;

  // Option #2: using the max2 function
  cout << "Using max2, max(v) = " << max2(v, 5, idx2);
  cout << " at index " << idx2 << endl;

  // Both approaches yield the desired results.
  // Choice depends on intended use.
  
  return 0;

} // end of main


// Option #1: max1 passes m and k by reference
void max1(float* a, int len, float& m, int& k) {
  m = a[0];
  k = 0;
  for (int i=1; i<len; i++) {
    if (a[i]>m) {
      m = a[i];
      k = i;
    }
  } 
} // end of max1


// Option #2: max2 passes k by reference, returns m
float max2(float* a, int len, int& k) {
  float m = a[0];
  k = 0;
  for (int i=1; i<len; i++) {
    if (a[i]>m) {
      m = a[i];
      k = i;
    }
  }
  return m;
} // end of max2


