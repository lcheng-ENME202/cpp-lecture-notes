// ENME 202
// 5b_dynamic_arrays.cpp
// Dynamic memory allocation for arrays

#include <iostream>
using namespace std;

// Prototype function to display an array:
void displayArray(float*, int);

int main(void) {

  float x[3] = {-1,0,1};
  float y[3];
  float z[3];

  cout << "Enter the 3 elements of y: ";
  for (int i=0; i<3; i++) {
    cin >> y[i];        // get y values from user
    z[i] = x[i]+y[i];   // Set z = x + y in vector form
  }

  cout << "z = ";
  displayArray(z,3);

  // Now, instead use "new" to allocate memory for a 3-element 
  // array of floats:
  float* x1 = new float[3];

  // Or split the declaration and allocation:
  float* y1;
  y1 = new float[3];

  // Dynamic allocation of an "array" is actually just creating
  // a pointer, not an array.  Thus we cannot use sizeof() to find
  // the size of the array.

  // Let's see where x1 and y1 are stored in memory:
  cout << "x1 is at memory location: " << x1 << endl;
  cout << "y1 is at memory location: " << y1 << endl;

  // Now load some data into y1
  cout << "Enter the 3 elements of y1: ";
  for (int i=0; i<3; i++) {
    cin >> y1[i];
  }
  
  // The following statement is LEGAL in C++
  // but ONLY for dynamically allocated arrays (pointers!)
  x1 = y1;
  
  // However, the above statement doesn't do what you 
  // may think it does...
  cout << "After x1 = y1 we have: " << endl;
  cout << "x1 = ";
  displayArray(x1,3);

  // Everything looks OK so far, but consider:
  
  y1[1] = -3.1415926;    // change y1 
  cout << "After setting y1[1] to -pi, we have:" << endl;
  cout << "x1 = ";
  displayArray(x1,3); // display x1
  cout << "y1 = ";         
  displayArray(y1,3); // display y1


  // Huh?  What happened??

  // For the dynamically allocated arrays x1, y1, the
  // statement x1=y1 makes the memory address associated with
  // x1 the same as the memory address associated with y1.
  // It does NOT copy array elements, only the MEMORY ADDRESS
  // This is known as a "SHALLOW COPY" of an array.  We can confirm
  // this:
  cout << "Now x1 is at memory location: " << x1 << endl;
  cout << "And y1 is at memory location: " << y1 << endl;

  // Thus, the statement x1=y1 simply causes variable x1 to refer
  // to the same chunk of memory as y1 does.  Thus changing 
  // an element of y1 will change the same element of x1.
  // x1 and y1 are now synonyms for the same block of memory.
  
  // Mmmm...what happened to the memory originally allocated
  // for x1???  "Memory Leak"!!!!
  
  // Actually copying all elements of an array at one address to the
  // elements of an array at a different address is called a
  // "DEEP COPY", and C++ will NEVER do this natively for dynamically
  // allocated memory.

  return 0;
}


void displayArray(float* a, int n) {
  cout << "[ ";
  for (int i=0; i<n; i++) {
    cout << a[i] << " ";
  }
  cout << "]\n";
}