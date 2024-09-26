// ENME 202
// 4b_functions_pass_array_by_reference1.cpp
// Functions - passing arrays by reference (1/2)

#include <iostream>
#include <cmath>
using namespace std;

// Sometimes we need functions to work on entire arrays,
// not just individual elements of those arrays.  Here is
// the prototype of a "avg" function that will average all 
// the elements in the array it is given as input:
float avg(float*, int);

// float* is a declaration that the input
// to the function is of type "array of floats"
// Generically <type>* means "array of <type>" in C++
// so we could have double*, int*, etc as the needs
// of our program demand. 

// At a deeper level, a variable of type float* is called 
// a "pointer", as it points to the base memory location 
// where the variable value (of type float) will be stored.


int main(void) {

  float v[5];   // declare a 5-element array

  // Note that it would be convenient to define the array
  // size using a variable, and reference this variable
  // instead of "hard-coding" the array length of 5 below.
  // However, we cannot do this!  C++ does not allow us
  // to define arrays using a variable for the length.
  // More precisely, some compilers will allow it, but the
  // resulting code is not compliant with C++ standards, and
  // can result in problems.  This is a topic we will discuss
  // in detail when we talk about "dynamic memory allocation".

  int len = sizeof(v)/sizeof(v[0]);

  cout << "\nEnter the 5 elements of v: ";
  for (int i=0; i<len; i++) {
    cin >> v[i];
  } 
  cout << "Average of elements in v: " << avg(v,len) << endl;
  // Why *two* inputs for avg()??  See below!

  return 0;
}


// Below is a version of avg() which replicates the ability of 
// the correponding Matlab function
// averaging all the elements in an array.  
//
// However, we must remember always that C++ 
// DOES NOT KNOW THE SIZES OF ARRAYS! 
//
// Functions with array inputs ALWAYS need to be told 
// (via an additional input) the length of the array.
//
// Why?
//
// There is NO equivalent "length" command as in Matlab,
// nor would it even be possible to create one! 
// We previously used sizeof(array)/siezof(array[0]) to
// find the array length, but this won't work here.
// We can use sizeof() when dealing with individual 
// pre-defined arrays becuase the compiler keeps track of
// the array size, but since different arrays can be
// passed to a function the compiler does not know
// how to apply sizeof() to these passed arrays.
//
// When you pass an array to a function, you are not
// passing the array itself, but simply a POINTER to the
// memory location where the array begins, and thus 
// sizeof(array) is determined at "runtime" rather than
// "compile time" and returns the size of the pointer instead 
// of the amount of memory assigned to the array itself.

float avg(float* var, int len) {
  float mysum = 0;
  for (int i=0; i<len; i++) {
    mysum += var[i];
  }
  float myavg = mysum / len;
  return myavg;
}


