// ENME 202
// 6c_fileout.cpp
// Streaming data to a file

/* 
foo.dat (copy & paste into a new file to use):
-2 3
5 -7.2
3.14e-02 -6.2
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(void) {

  // Files to output things to work similarly to ifstream,
  // using instead ofstream for holding an output file

  // Here we'll read in data from foo.dat, do some simple
  // number crunching, and output the results
  // to a different file sum.dat.

  ifstream fin("foo.dat");
  ofstream fout("sum.dat");
  	
  // The ofstream class associates an object (called fout here) with a
  // file for writing (sum.dat here).  The file will be created in
  // the "default" location.  
  // 
  // CAREFUL: If sum.dat already exists, it will be overwritten!

  int N=3;  // Assume we know the number of value pairs this time

  float v1[3], v2[3], v3[3];
	
  if (!fin.is_open()) {
    // Can't open the file, so exit
    cout << "Error opening foo.dat -- exiting" << endl;
  }
  else {
    // Read the data in each column into two arrays
    for (int i=0; i<N; i++) {
      fin >> v1[i] >> v2[i];
    }
    
    // Compute the sum of the two arrays
    for (int i=0; i<N; i++) {
      v3[i] = v1[i]+v2[i];
    }

    // Let's output v3 to the screen
    cout << "v1+v2= " << endl;
    for (int i=0; i<N; i++) {
      cout << v3[i] << endl;
    }

    // Also a good idea to check if there were problems 
    // opening the file for output, like we did for input.
    // For example, you might not have "write permission" 
    // for the current folder!
    if (! fout.is_open()) {
      cout << "Error opening sum.dat for writing -- exiting." << endl;
    }
    else {
      // Write the data to the file in the same format as before
      // using fout instead of cout	
      fout << "v1+v2=" << endl;
      for (int i=0; i<N; i++) {
        fout << v3[i] << endl;
      }
    }
 
  }

  // The file will close automatically when it goes 
  // "out of scope" (in this case, when main() ends.
  // To close the file manually, use: fout.close()
  
  return 0;

}
