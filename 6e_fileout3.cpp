// ENME 202
// 6e_fileout3.cpp
// Streaming to a file with format control
// using the <iomanip> library

#include <iostream>
#include <fstream>
#include <iomanip>   // library for I/O format control

using namespace std;

int main(void) {

  ifstream fin("foo3.dat");
  ofstream fout("sum3.dat");

  int N=3;
  float v1[3],v2[3];
	
  if (!fin.is_open()) {
    // Can't open the file, so exit
    cout << "Error opening foo3.dat -- exiting" << endl;
  }
  else {
    // Read the data in each column into two arrays
    for (int i=0;i<N;i++) {
      fin >> v1[i] >> v2[i];
    }
    
    float v3[3],v4[3];

    for (int i=0;i<3;i++) {
      v3[i] = v1[i]+v2[i];
      v4[i] = v2[i]-v1[i];
    }
		
    // As always, check before writing to the file
    if (!fout.is_open()) {
      cout << "Error opening sum.dat for writing -- exiting." << endl;
    }
    else {
      // Write into columns as before, but use more 
      // visual formatting for easy human reading
      
      for (int i=0;i<N;i++) {
	      fout << left << setw(10) << v3[i] << v4[i] << endl;
        //      ^^^^    ^^^^
        // setw(n) forces display of each number to use n 
        // positions in display,filling in with blank spaces if needed
        // Effect is to visually arrange numbers on a line 
        // into neat (as opposed to ragged) columns
        			
        // keyword "left" forces left justification of numbers within the spaces
        // dictated by setw (default is *right* justification, 
        // which doesn't look as nice sometimes ). 

        // Note: both setw and left require iomanip library
      }
      cout << "Results written to sum3.dat" << endl;
    }

  }
  return 0;

}
