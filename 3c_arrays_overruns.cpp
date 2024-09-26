// ENME 202
// 3c_array_overruns.cpp
// C++ Array Overruns

#include <iostream>
using namespace std;


int main(void) {

  float v[3];
  // v is a length 3 float array
  // C++ allocates 32 bits (4 bytes) for each float value, so v takes up
  // a total of 12 bytes of memory.
  
  cout << "Base address of array v:  " << v << endl;

  // Overwrite the 4 kB of memory starting at base address for v:
  // (Remember: C++ has only reserved the first 12 of those
  //  bytes for our program to use)
  for (int i=0; i<7; i++) {
    cout << "Writing at " << i*sizeof(float);
    cout << " bytes past base address";
    cout << " (address=" << v+i*sizeof(float) << ", index=" << i << ")";
    cout << endl;
    v[i] = -1.0;
  } 

  // In this loop, we are changing "elements" of v far past the
  // declared end of this array.  However, C++ doesn't care!  It 
  // just keeps advancing through the computer's memory the requested 
  // number of positions past the base address for v.  Eventually we
  // will either 1.) reach the end of memory (extremely rare), or 2.)
  // run into memory which is marked as in use by another program or
  // part of the OS itself (most common).
  
  // Either case will cause the operating system to shut our program
  // down (this is an OS feature known as "protected memory").  However,
  // until we reach protected memory, we can read or overwrite vast
  // swaths of the computers memory in C++ by overrunning an array.  
  //                   BE CAREFUL!!
  
  // Array overruns can screw up calculations your own program is doing,
  // cause infinite loops to occur (if a loop variable, flag, or other
  // termination condition gets overwritten), and other very nasty things.
  
  return 0;
}
