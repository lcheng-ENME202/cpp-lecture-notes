// ENME 202
// 4c_functions_pass_array_by_reference2.cpp
// Functions - passing arrays by reference (2/2)

#include <iostream>
#include <cmath>
using namespace std;

// Passing a pointer to a function allows us access to the
// memory location where the original variable is stored.
// We can take advantage of this to change the value (or 
// values in the case of an array) within the function, even
// though the function does not know about the original
// variable name!

float avg(float*, int);   // Prototype of avg function

int main(void) {

  float v[5];

  // get array values from user:
  cout << "Enter the 5 elements of v: ";
  for (int i=0;i<5;i++) cin >> v[i];

  // display array values:
  cout << "v=[";
  for (int i=0;i<5;i++) cout << v[i] << " ";
  cout << "]" << endl;
  
  // call our avg() function:
  float vavg = avg(v,5) ;
  cout << "Average of elements in v: " << vavg << endl;
  
  // display the array values...look at the 1st element:
  cout << "Now v=[";
  for (int i=0;i<5;i++) cout << v[i] << " ";
  cout << "]" << endl;
  
  return 0;

}

// Definition of avg() function
float avg(float* var, int len) {

  float myavg = 0;
  
  // Calculate the average:
  for (int i=0;i<len;i++) {
    myavg += var[i];
  }
  myavg /= len;
 
  // When ARRAYS are passed to functions in C++ (using a pointer)
  // the function does NOT make a copy.  var (in avg) corresponds
  // to the SAME memory addresses as v (in main).  Thus, changing
  // the elements of var in avg() WILL change the elements of 
  // v in main.  This happens ONLY with arrays (or other pointers),
  // not with regular scalar (non-array) variables.

  var[0] = -3.14;

  // The array is said to be "passed by reference" (as opposed to
  // "by value (copy)" which is the standard for regular (scalar)
  // variables.  i.e. the function "references" the array by receiving
  // its location in memory, as opposed to making a copy of the array
  // and working with that copy.  

  // This is done in C++ (and other programming languages) for speed and
  // efficiency.  It is far faster to avoid copying a (potentially very
  // long array) unless it is absolutely necessary to do so.  If it *is*
  // necessary, C++ of course has techniques that allow a programmer to
  // construct such a copy (as we shall see), but it is up to them whether
  // to use this capability in a given situation.
 
  return myavg;
}

