// ENME 202
// 6d_fileout2.cpp
// Streaming data to a file - simple output formatting

#include <iostream>
#include <fstream>
using namespace std;

int main(void) {

  ifstream fin("foo.dat");

  int N=3;
  float v1[3], v2[3];
  
  if (!fin.is_open()) {
    cout << "Error opening foo3.dat -- exiting" << endl;
  }
  else {
    // Read user data into columns (two arrays)
    for (int i=0; i<N; i++) {
      fin >> v1[i] >> v2[i];
    }
    
    // We can impose whatever format we want on the
    // calculations we do.
    
    // Now suppose we want to output the sum v1+v2 
    // as the first column in the output file, and 
    // the difference v2-v1 as the second column:
    
    ofstream fout("sum2.dat");
    
    if (!fout.is_open()) {
      cout << "Error opening sum.dat for writing -- exiting." << endl;
    }
    else {
      for (int i=0;i<N;i++) {
        fout << v1[i] + v2[i] << " " << v2[i] - v1[i] << endl;  // write data in columns
      }
      cout << "Results written to sum2.dat" << endl;
    }

  }

  return 0;
}
