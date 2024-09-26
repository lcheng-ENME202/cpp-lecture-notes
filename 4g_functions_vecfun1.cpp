// ENME 202
// 4g_functions_vecfun1.cpp
// Functions - vector math example (1/2)

#include <iostream>
#include <cmath>
using namespace std;

// C++ cannot evaluate a statement like "v3 = v1+v2"
// when v1, v2, and v3 are arrays.
//
// Let us try to write a function to duplicate the Matlab 
// behavior for v3 = v1 + v2.
//
// It would make sense to try something like
//    v3 = vecsum(v1,v2,len);
//
// However, functions in C++ CANNOT return arrays!
// (actually, this is not quite true, as we will 
// see shortly).

// Instead, we can directly modify an array given
// as an input to the function, as we have seen.
// Thus, for functions whose results are contained in 
// in array, we can pass (as an input) an empty array 
// that the function can deposit its results into.  main
// can see the changes in this array and use them to display
// or for subsequent calculations.

// Below is the way we need to specify 
// a function that can do array arithmetic 
// (here addition) like Matlab does:

void vecsum(float*, float*, float*, int);

// This function has NO outputs (indicated by the "void"
// keyword.)  The results of its calculation will be seen in 
// main by looking at how the third input to the function has 
// been changed after the function runs.

int main(void) {

  float v1[6], v2[6], v3[6]={1,2,3,4};
  int len = 6; 
	
  cout << "v3 = [ ";
  for (int i=0; i<len; i++) cout << v3[i] << " ";
  cout << "]" << endl;
  
  cout << "Enter the 6 elements of v1: ";
  for (int i=0; i<len; i++) cin >> v1[i];

  cout << "Enter the 6 elements of v2: ";
  for (int i=0; i<len; i++) cin >> v2[i];
	
  // Call vecsum function to add arrays element-by-element
  // Result of its calculations will be changes to array v3
  vecsum(v1,v2,v3,len); 
  cout << "- called vecsum(v1,v2,v3,len); ..." << endl ;

  // Equivalent to v3=v1+v2 in Matlab
  
  cout << "v3 = [ ";
  for (int i=0; i<len; i++) cout << v3[i] << " ";
  cout << "]" << endl;
	
  return 0;
}


void vecsum(float* x, float* y, float* z, int n) {

// Vecsum will modify its third input (z).
// Modifying z in vecsum WILL directly modify
// variable v3 in main(), since v3 is the third
// input to vecsum() in main() above. 

  for (int k=0; k<n; k++) {
    z[k] = x[k] + y[k];
  }

}

