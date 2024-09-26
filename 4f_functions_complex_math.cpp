// ENME 202
// 4f_functions_complex_math.cpp
// Functions - complex arithmetic example

#include <iostream>
#include <cmath>  
using namespace std;

// EXAMPLE: passing arrays to a function to implement
// the addition and multiplication of complex numbers

// Representing complex numbers as 2-element arrays
// such that z = [real, imag] provides one way to 
// perform complex calculations

// (We'll be able to do much better using "structs")

// Here are the function prototypes.  We will pass 3 
// pointers -- one each for the complex numbers (arrays)
// to add together, and one for the array to hold
// the result of the given operation:

void cadd(float*, float*, float*);
void cmul(float*, float*, float*);
//          ^       ^        ^     
//          |       |        |     
//          |       |        result
//          |       z2 array
//          z1 array

int main(void) {

  float z1[2], z2[2], z3[2];  // our complex numbers
  float z1plus2[2];           // intermediate result
  float z4[2];                // final result
  
  // Store real part as first element of each array
  // and imagimary part as second element
  cout << "\nEnter real and imag parts of z1: ";
  cin >> z1[0] >> z1[1];

  cout << "\nEnter real and imag parts of z2: ";
  cin >> z2[0] >> z2[1];

  cout << "\nEnter real and imag parts of z3: ";
  cin >> z3[0] >> z3[1];

  // Now, let's calculate z4 = z3 * (z1 + z2)
  // (note we'll need an intermediate variable for the sum)
  cadd(z1, z2, z1plus2);
  cmul(z3, z1plus2, z4);
  
  // Little bit awkward, but way better than trying to clutter
  // main with the details of each calculation!
  
  cout << "z3*(z1+z2) = ";
  
  // Print out result: note that the block of code below would 
  // be a good candidate to put in a separate function, 
  // perhaps called cshow()?  
  cout << z4[0];
  if (z4[1]>=0) {
    // minus sign appears automatically if z4[1] < 0
    cout << "+";
  }
  cout << z4[1] << "j";
  cout << endl;

  return 0;
}

void cmul(float* z1, float* z2, float* result) {
  // z1 and z2 are LOCAL to the function.  They are
  // not the same as z1 and z2 in main()!

  // Remember: we are using here the convention that
  // real part = 1st element of array (index 0)
  // imag part = 2nd element of array (index 1)

  // There is nothing in C++ which dictates this, since
  // C++ doesn't know about complex numbers (natively).
  // The above is simply a design decision we have made
  // about how to map the mathematics of complex numbers
  // onto the concepts C++ understands.

  // Find the product, and store result in the 2-element
  // array 'result' passed by reference to the function.
  result[0] = z1[0]*z2[0] - z1[1]*z2[1];
  result[1] = z1[0]*z2[1] + z2[0]*z1[1];
}

// Similar (but simpler) idea for complex addition
void cadd(float* z1, float* z2, float* result) {

  result[0] = z1[0] + z2[0];
  result[1] = z1[1] + z2[1];

  // Note: both this and cmul are void (no output) functions,
  // and there is no return statement.
}

