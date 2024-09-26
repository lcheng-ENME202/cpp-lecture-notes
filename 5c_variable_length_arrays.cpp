// ENME 202
// 5c_variable_length_arrays.cpp
// Variable length arrays

#include <iostream>
#include <cmath>
using namespace std;

float sum(float*, int);

// What if we want the size of our array to be determined
// only after the program starts running?  Remember that
// you need to declare the length of any array you use
// in your code, but here we may not know the required 
// length ahead of time.
//
// In programming, we talk about "compile-time" and "run-time" --
// in this lingo, we have so far always decided the lengths of
// arrays at compile-time, but we'd like to be able to decide
// the lengths at run-time instead.
//
// Fortunately, C++ offers a way to implement such "variable
// length arrays", using dynamic memory allocation.

int main(void) {

  int n;
	
  cout << "Enter size of array: ";
  cin >> n;

  // The line below is FORBIDDEN by the C++ language standard:

  //    float v[n];

  // (Caution! Some compilers may permit this, since it IS valid
  // in "regular" C.  However, we will be checking that your code is
  // conformant with C++ standards, so you should NEVER USE a 
  // construction like the above!!)
	
  // This is how you do the equivalent thing in C++
  float* v = new float[n];
	
  // The "new" command in C++ requests from the operating system
  // additional memory for the program to use. In the case above,
  // we are requesting enough space to store a float array of 
  // length n.  The address of the first element of that block
  // of memory is assigned to the pointer v.
  //
  // As a pointer, v can now be used as if it were an array:
  cout << "Enter the " << n << " elements of v: ";
  for (int i=0; i<n; i++) {
    cin >> v[i];
  }

  cout << endl << "v = [ ";
  for (int i=0; i<n; i++) {
    cout << v[i] << " ";
  }
  cout << "]" << "\n\n";
	
  cout << "The elements in v sum to: " << sum(v,n) << "\n\n";	
	
  return 0;

}

// Note: sum function is unchanged -- it doesn't care whether the
// passed parameter is an array or a pointer:
float sum(float* var, int len) {
  float mysum = 0;
  for (int i=0; i<len; i++) mysum += var[i];
  return mysum;
}

