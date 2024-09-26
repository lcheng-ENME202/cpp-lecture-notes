// ENME202
// Using variables in C++

#include <iostream>
using namespace std;

int main(void) {

	// Variables must be "declared" before use
	// by specifying their type and name

	// "int" is the default precision integer type
	int a;
	int b;

	// You can declare multiple variables in a single statement
	int c,d;

	// Apart from the necessary declaration step, variables and
	// assignment work in C++ identically to Matlab
	a = 2;
	b = 4;
	c = a-b; 
	d = a/b;

	cout << "a = " << a <<endl;
	cout << "b = " << b << endl;
  cout << "a-b = " << c << endl;
	cout << endl;

	// A more complicated output chaining to make the 
	// printed result appear more natural
	cout << a << "-" << b << " = " << c << endl;

	// Look at the division calculation
	cout << a << "/" << b << " = " << d << endl;
	cout << endl; 

	// Note that if you tell C++ you are working with integers,
	// decimal parts of integer calculations are IGNORED (not rounded)
	a = 5;
	d = a/b;
	cout << a << "/" << b << " = " << d << endl;
	cout << endl; 

	// This happens also with "literal" number calculations (where we
	// don't use variables in the calculation)
	cout << "3/4 = " << 3/4 << endl;
	cout << endl;

	// If you need a decimal result when working with literal integers,
	// you'll need to include a decimal point after one of the integers
	// in the calculation.  This will force C++ to return a "floating point"
  // value from the division operation.

	cout << "3/4 = " << 3/4.0 << endl;

	// What do we do if we need to store floating point numbers in variables?
	// Answer: use an appropriate variable type: float

  return 0;
}
