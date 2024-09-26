// ENME 202
// 8a_overloading_complex.cpp
// Operator Overloading

// C++ allows us to redefine how operators like +, -, ++, +=, 
// etc., as well as streaming operators (<<, >>) work when 
// applied to our custom structs.  
//
// This process is called "operator overloading" since we are
// overloading the normal functionality with a custom
// operator definition.

#include <iostream> 
using namespace std;

// Define a struct for a complex number:
struct Complex {   
  float a;  // real part
  float b;  // imag part
};

// Prototypes for "operator overloads":
//
// These are definitions (prototypes) of what C++ should do when
// an operator appears next to one of our structures
// (without such overloads, the C++ compiler will throw
// an error if symbols like + or << appear next to our
// structures).
Complex operator+(Complex,Complex);
Complex operator*(Complex,Complex);

// Overloads for input/output stream operators.
// Note the new "ostream" and "istream" variable types.
// We must pass I/O streams by reference, and
// each stream overload function must return the same
// stream reference used in the input:
ostream& operator<<(ostream&,Complex);
istream& operator>>(istream&,Complex&);

int main(void) {

  Complex z[3];
  Complex result;

  // We don't have a cget() member function in this code, so
  // use a manual loop to get complex values from user:
  cout << "Enter real then imag parts for 3 complex numbers:\n";
  for (int i=0; i<3; i++) {
    cin >> z[i];    // "operator>>(cin,z[i])"
  }

  // Instead of doing complex math using functions like cadd()
  // and cmul(), operator overloading lets us use + and *
  // more naturally:
  result = z[2] * (z[0] + z[1]);  // "operator*(z[2], operator+(z[0], z[1]))"
  cout << "result = " << result << endl;  // "operator<<(cout,result)" for 2nd "<<"

  return 0;
}


// Rename cadd function to "operator+" 
// Will be called when "+" appears between two Complex structures
Complex operator+(Complex foo, Complex bar) {
  Complex bas;
  // Implement rules of complex number addition
  bas.a = foo.a + bar.a;
  bas.b = foo.b + bar.b;
  return bas;
}

// Rename cmul function to "operator*"
// Will be called when "*" appears between two Complex structures.
Complex operator*(Complex foo, Complex bar) {
  Complex bas;
  // Implement rules of complex number multiplication
  bas.a = foo.a*bar.a-foo.b*bar.b;
  bas.b = foo.a*bar.b+bar.a*foo.b;
  return bas;
}

// Rename cdisplay function to "operator<<"
// Will be called when a Complex structure appears right of "<<"
// Couple of minor technical changes also needed here, see comments
// after function...
ostream& operator<<(ostream& o, Complex z) {
  o << z.a;
  if (z.b > 0) o << "+" << z.b << "j";
  else if (z.b < 0) o << z.b << "j";
  return o;
}
// NOTES:
//
// The first input of this operator function must always be its output
//
// Output type must be ostream& (same as first input)
//
// using the first input "o" as the target source for the 
// output, instead of assuming cout, allows this function to 
// also work unchanged for FILE output as well.  (In the main 
// function above, "o" passes as cout when this program is run.)
//
// An "ostream" variable can be EITHER cout or an ofstream variable 
// (correponding to a disk file).
// 
// C++ requires ostream to ALWAYS be passed by reference,
// and this variable should also be the defined OUTPUT of this
// overloaded function


// Rename cget2 function to "operator>>"
// Will be called when a Complex structure appears right of ">>"
//  Couple of minor technical changes also needed here
istream& operator>>(istream& i, Complex& z) {
  i >> z.a >> z.b;
  return i;
}
// Notes:
//
// The first input of this operator function must always be its input
//
// Output type must be istream& (same as first input)
//
// using the first input "i" as the target source for
// the input, instead of assuming cin, allows this function to 
// also work UNCHANGED for file input as well. (In the main function
// above, "i" is passed as cin when this program is run.)
//
// An "istream" variable can be EITHER cin or an ifstream variable (file)
// C++ requires this variable type to always be passed by reference
//
// Finally, the second input to operator>> should ALSO be passed 
// BY REFERENCE, since the entire purpose of this function is to
// load that variable with data (from the keyboard or file) and 
// have main be able to see the changes. 


