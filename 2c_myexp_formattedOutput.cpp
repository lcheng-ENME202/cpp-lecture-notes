// ENME 202
// 2c_myexp_formattedOutput.cpp
// myexp() with controlled output precision
// using the iomanp library.

#include <cmath>
#include <iostream>

// Include library to change precision and format of displayed numbers:
#include <iomanip>    


using namespace std;

int main(void) {

  float tol = 1e-7;
  float diff = 1;
  float y = 0, yprev = 0;
  int k = 0;
  float x, fact = 1;

  // Alternately, we could have declared the 32 bit floats as
  // doubles (double precision floating point numbers).  
  // "Double" represent floating point numbers using
  // 64 bits, and have a precision of about 15 significant digits
  // (identical to Matlab's "eps").
  // Use when high accuracy is more important than
  // program speed or size.

  // Get desired value of x from keyboard 
  cout << "Enter the value of x: ";
  cin >> x;

  // Keep adding terms until difference between 
  // successive partial sums is less than tol
  while (abs(diff)>=tol) {
    yprev = y;          
    y += pow(x,k)/fact; 
    diff = y-yprev;     
    k++;        	
    fact *= k;   	 
  }

  // Display result with default precision
  cout << "After " << k << " terms in the series, ";
  cout << "exp(" << x << ")= " << y << endl;
  cout << "The exact value is " << exp(x) << endl << endl;

  cout << setprecision(20); // Increase number of digits shown
  cout << "After " << k << " terms in the series, ";
  cout << "exp(" << x << ")= " << y << endl;
  cout << "The exact value is " << exp(x) << endl << endl;

  cout << scientific; // Change to scientific notation format
  cout << setprecision(3); // Change number of digits shown
  cout << "After " << k << " terms in the series, ";
  cout << "exp(" << x << ")= " << y << endl;
  cout << "The exact value is " << exp(x) << endl;

  return 0;
}
