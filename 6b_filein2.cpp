// ENME 202
// 6b_filein2.cpp
// Streaming data from a file

/* 
foo.dat (copy & paste into a new file to use).  This time
the data is in 2 columns (to be read into 2 arrays):
-2 3
5 -7.2
3.14e-02 -6.2
*/

#include <iostream>
#include <fstream>

using namespace std;

// In this example, we want to read in values from 
// a file where the number of values is not initially
// known.
//
// The strategy will be to read through the file
// to count the number of values, without saving
// any information, and then re-read the data
// after declaring an array of the correct size.

int main(void) {

  ifstream fin("foo.dat");
 
  if (! fin.is_open()) {
    // Can't open the file, so exit
    cout << "Error opening file -- exiting" << endl;
    return 1 ;
  }
  // Find the number of values in the file:
  float dummy;
  int N=0;
  while(! fin.eof()) {  // eof = "end of file"
    fin >> dummy;       // read value into a dummy variable
    N++;                // increment the count
  }

  // This time, we will read the data in as 2 columns,
  // with each column placed into a separate array.

  if (N%2) {  // N%2 will be non-zero (true) iff N is odd
    cout << "There is an odd number of values in the data file" << endl;
    cout << "End program" << "\n\n";
  }
  else {
    cout << "There are " << N << " values in the file" << endl;
    cout << "(" << N/2 << " values in each column)" << endl;

    // Need to use dynamic memory allocation for the array
    // (do you understand why?):
    float* v1 = new float[N/2];  
    float* v2 = new float[N/2];  

    // First we must return to the beginning of the file to
    // read & store each value to an array:
    fin.clear();            // Clear all status flags internal to fin
    fin.seekg (0, fin.beg); 
    //   ^^^
    //    |___ seekg() is an ifstream member function that
    //         sets the position in the input sequence
    //
    // Alternate syntax (independent of ifstream object name:
    //     fin.seekg(0,ios::beg)

    // Stream data from the file into the array:
    for (int i=0; i<N/2; i++) {
      fin >> v1[i];
      fin >> v2[i];
    }
    // Display the resulting arrays:
    cout << "v1 = ";
    for (int i=0; i<N/2; i++) cout << v1[i] << " ";
    cout << endl;
    cout << "v2 = ";
    for (int i=0; i<N/2; i++) cout << v2[i] << " ";
    cout << endl;
  }

  return 0;

}

