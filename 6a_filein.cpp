// ENME 202
// 6a_filein.cpp
// Streaming data from a file

/* 
foo.dat (copy & paste into a new file to use):
-2 3 5 -7.2 3.14e-02  -6.2
*/

#include <iostream>

#include <fstream>
// fstream contains the C++ libraries that access
// external files (stored on hard drive, flash drive, etc)
// for either output (ofstream) or input (ifstream).

using namespace std;

int main(void) {

  // Open file "foo.dat" for reading data 

  // Use a variable of type "ifstream" ("(I)nput (F)ile STREAM) 
  // to represent files you READ from.  
  // We here associate a C++ variable (here called fin) 
  // of type ifstream with the desired filename ("foo1.dat")  
  // using the following statement:

  ifstream fin("foo.dat");

  // fin() is NOT a function!
  //
  // ifstream is a "class"
  // fin is a "member" of the class ifstream
  // (and thus an "object" of type ifstream)
  //
  // "fin" can be any variable name you want.

  // When opening a file, the file is assumed to be in the 
  // the same directory as the main code itself.
  //
  // To open files in another directory, the complete path to
  // the file's location must be specified. The details for this
  // vary with operating system. We will not study this, and will
  // assume the file we are reading is in the default location.

  int N=6;     // Assume we know how many values are in the file

  float v[6];  // Will hold the data we read in from the file

  // Always a good idea to check if there was an error 
  // opening the file (like, it could not be found).
  // C++ will let you try to read from an ifstream even if the file
  // wasn't found, but you will only get garbage as a result.
  //
  // For our ifstream object (fin), the associated function
  //    fin.is_open() 
  // returns a value of 1 (TRUE) if the file was opened 
  // successfully, otherwise it returns 0 (FALSE). 
  //  
  // is_open() is a "member function" (or "method") of the 
  // ifstream class.
 
  if (! fin.is_open() ) {    // fin is NOT open
    cout << "Error opening file -- exiting" << endl;
    return 1;
  }

  // Stream data from the file into the array:
  for (int i=0; i<N; i++) {
    fin >> v[i];
  }
  // Display the resulting array:
  cout << "\nThe file contains the numbers: " << endl;
  for (int i=0; i<N; i++) {
    cout << v[i] << " ";
  }
  cout << "\n\n";

  return 0;

}

