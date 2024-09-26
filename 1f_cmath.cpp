// ENME 202
// C numerics library: <cmath>  

// <cmath> provides "advanced" math functions
// (which in C++ is anything more than standard arithmetic)

#include <cmath>
#include <iostream>
using namespace std;

int main(void) {

  float a,b;

  cout << "Enter two numbers (a b): ";
  cin >> a >> b;

  // pow(a,b) is equivalent to a^b in Matlab
  cout << "pow(a,b) = " << a << "^" << b << " = " << pow(a,b) << endl;
	
  // trig functions and their inverses:
  // sin, cos, tan, asin, acos, atan 
  // These all use RADIANS (no degree option)
  cout << "sin(" << b << ") = " << sin(b) << endl;
	
  // abs()
  cout << "abs(b) = |" << b << "| = " << abs(b) << endl;

  // exp()
  cout << "exp(b) = e^" << b << " = " << exp(b) << endl;
  
  // log() (base e)
  cout << "log(b) = ln(" << b << ") = " << log(b) << endl;

  // log10() (base 10)
  cout << "log10(b) = log(" << b << ") = " << log10(b) << endl;

  // sqrt()
  cout << "sqrt(a) = square root of " << a << " = " << sqrt(a) << endl;	
		
  // pi is not a built-in variable in C++.  If you need it, 
  // define it using trig functions, e.g.:
  float pi = acos(-1);
  cout << "acos(-1) = pi = " << pi << endl;
	
  // Here is a very common example of where forgetting the 
  // "integer math" rules can hurt you:
  cout << "pow(8,1/3) = " << pow(8,1/3) << endl;
	
  // C++ says the result is 1.  Ooops!
  // Do you see what went wrong and how to fix it?

  return 0;
}
