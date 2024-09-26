// ENME 202 / ENAE 202
// 7c_structs3.cpp
// Structs, part 3

//
// Member functions
//

#include <cmath> // needed for pow() function below
#include <iostream>
using namespace std;

// Here we will extend our Complex struct by adding "member functions".

class Complex {
  public:
  float real; // real part of complex number
  float imag; // imag part of complex number

  // Member functions follow...

  // Assign values from user input:
  void cget() {          // nothing is passed...
    cin >> real >> imag; // real, imag are not declared...
    // our access to real and imag in this member function
    // is called "implicit" because it assumes these variables
    // apply to the current structure accessing the member function.
  }

  // Return the magnitude of the complex value:
  float mag() { return sqrt(pow(real, 2) + pow(imag, 2)); }

  // Convert cdisplay() to a member function:
  void cdisplay() {
    cout << real;
    if (imag > 0)
      cout << "+" << imag << "j";
    else if (imag < 0)
      cout << imag << "j";
    cout << endl;
  }
};

// "Member functions" can be called using the same dot notation
// used to access class variables.
//
// We could instead define member functions outside the
// class declaration using slightly different syntax
// (that we will not discuss this here).

int main(void) {

  // Define an array of 3 Complex structs:
  Complex z[3];

  cout << "Enter real and imag parts for z[0]: ";
  z[0].cget(); // cget() is now a member function of Complex, so
               // use the dot notation to access the function.
  cout << "Enter real and imag parts for z[1]: ";
  z[1].cget();

  cout << "Enter real and imag parts for z[2]: ";
  z[2].cget();

  // Access the cdisplay() and mag() member functions to
  // display the corresponding info:
  for (int i = 0; i < 3; i++) {
    cout << "z[" << i << "]: " << endl;
    z[i].cdisplay();
    cout << "magnitude = " << z[i].mag() << "\n\n";
  }
}
