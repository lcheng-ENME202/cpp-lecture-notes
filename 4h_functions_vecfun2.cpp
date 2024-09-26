// ENME 202
// 4h_functions_vecfun2.cpp
// Functions - vector math example (2/2)

#include <iostream>
#include <cmath>
using namespace std;

// Topic: using dynamic memory allocation to return an
//        array (pointer) from a function

// Recall our original prototype for vecsum, in which the array
// used to store the result is passed by reference to the function:
//
//    void vecsum(float*, float*, float*, int);
//
// Wouldn't it be nice if we could instead return a pointer (float*)
// to the result, as in the following prototpye?

float* vecsum(float*, float*, int);

// We previously said that this will not work, because C++ cannot
// return an array.  This is not entirely true!
//
// When an array is initialized as "myarray = float[5]" in a 
// function, it resides in "stack" memory, and will be released 
// once the function ends. When a function is called, a block
// of memory is reserved at the top of the stack to hold
// any local variables. When the function ends, the block is
// "forgotten" so that the memory can be re-used.  As a result, 
// any stack memory set aside for local variables in a function 
// can no longer be relied upon once the function ends.
//
// However, there is a way around this!  In addition to the stack,
// there is another block of memory called the "heap".  While there
// can be many different blocks of memory set aside for the stack,
// there is only one block of memory for the heap.  The heap
// is shared by the entire application, and is only released when
// the entire application terminates. The heap is for dynamic
// memory allocation: portions of the heap can be dynanically
// reserved and released at runtime (after the code has been
// compiled). 
//
// We can force a variable to reside in the heap through the
// process of "dynamic memory allocation" using the "new" keyword.
// THIS IS OUR NEXT TOPIC.  To demonstrate the concept, below is a
// revised vecsum() function that employs dynamic memory allocation
// to return a pointer to an array.


int main(void) {

  float v1[4], v2[4];

  cout << "Enter the 4 elements of v1: ";
  for (int i=0; i<4; i++) cin >> v1[i];

  cout << "Enter the 4 elements of v2: ";
  for (int i=0; i<4; i++) cin >> v2[i];

  float* v3;    // create a new pointer to hold v3
  v3 = vecsum(v1, v2, 4);    // assign vecsum() result to v3
  cout << "\nv3 in main() stored at:  " << v3 << endl;

  // Display resulting elements in v3 = v1 + v2:
  cout << "v1 + v2 = [ ";
  for (int i=0; i<4; i++) cout << v3[i] << " ";
  cout << "]" << endl;

  return 0;
}

float* vecsum(float* x, float* y, int n) {
  float* z = new float[n];    // dynamically allocate memory for z
  for (int i=0; i<n; i++) {
    z[i] = x[i] + y[i];
  }
  cout << "z in vecsum() stored at: " << z;
  return z;   // return the pointer to the array
}

// There is one (BIG!) problem with this code...
//
// Every time vecsum is called, a new array will be created,
// eating up heap memory.  To avoid this, we will need to learn
// how (and when) to *release* dynamically-allocated memory.  

