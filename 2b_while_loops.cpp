// ENME 202
// 2b_while_loops.cpp
// while() loops

#include <iostream>
#include <cmath>

using namespace std;

int main(void) {

	int i = 0;

	// A simple while loop to print an incrementing value 11 times
	while (i <= 10) {  
	  cout << "i = " << i << endl;
	  i = i+1; 
	}

	// Note that C++ while loops are identical to Matlab while
	// loops, except:
	// (1) braces are used instead of the "end" keyword to delimit
	//     the body of the loop
	// (2) the logical expression following keyword "while" MUST
	//     be enclosed by parentheses (optional in Matlab)


  // The primary use of the while loop in C++, just like in
  // Matlab, is to repeat calculations when you don't know
  // ahead of time how often you need to repeat. (So, not the
  // best choice in the above example!)


  /* 
     Example: exp(x)

     compute an approximation to exp(x) from definition
     until partial sums converge to within tol, just like we
     did in Matlab.
  */

  float y = 0;  // accumulate the terms in the partial sums
  float yprev = 0;  // store previous sum (for convergence)

  // C++ has no "factorial" function like Matlab does
  // Thus, we need to use the extra variable "fact" in which we will
  // calculate k! for the partial sum terms.
  float fact = 1;
  int k = 0;

  // Get desired value of x: 
  float x ;
  cout << endl << "Enter the value of x: ";
  cin >> x;

  // Do the calculation with this value of x:
  // keep adding terms of the series until the difference between
  // successive partial sums is less than tol
  float tol = 1e-7;
  float diff = 1;    // Initial value can be anything >tol
  while ( abs(diff) > tol ) {
    yprev = y;            // yprev holds the previous value of the partial sum
    y += pow(x,k)/fact;   // y now holds the new value of the partial sum
    diff = y-yprev;       // difference between successive partial sums
    k++;        	  // increment k
    fact *= k;   	  // compute factorial manually
  }

  cout << "After " << k << " terms in the series, ";
  cout << "exp(" << x << ")= " << y << endl;
  cout << "The exact value is " << exp(x) << endl;

  return 0;

}
