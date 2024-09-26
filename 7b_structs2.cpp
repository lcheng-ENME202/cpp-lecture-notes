// ENME 202
// 7b_structs2.cpp
// Structs, part 2

//
// Passing structs by reference
//

#include <iostream> 
using namespace std;

struct Complex {
  float real;  // Used to hold real part of complex number
  float imag;  // Used to hold imag part of complex number
};

Complex cadd(Complex, Complex);
Complex cmul(Complex, Complex);
void cdisplay(Complex);

// Here we add another "convenience" function cget(), for 
// reading Complex variables from user input:

Complex cget(void);     // return a Complex value
void cget2(Complex&);   // pass Complex variable by reference
 
// In cget(), the data is loaded into a structure which
// is then returned as a new Complex value.
// 
// In cget2(), the Complex variable is passed BY REFERENCE
// so that when its data is changed in cget2(), main() will
// see those changes.

  
int main(void) {

  Complex z1, z2, z3;

  // Option 1 -- manually input data
  cout << "Enter real and imag parts of z1: ";
  cin >> z1.real >> z1.imag ;

  // Option 2 -- return a Complex struct
  cout << "Enter real and imag parts of z2: ";
  z2 = cget();
  
  // Option 3 -- pass by reference
  cout << "Enter real and imag parts of z3: ";
  cget2(z3); 

  // Show values
  cout << "z1, z2, z3 = " << endl;
  cdisplay(z1);   
  cdisplay(z2);   
  cdisplay(z3);   

  return 0;
}


// Read data from keyboard into a Complex structure
Complex cget(void) {
  Complex z;
  cin >> z.real >> z.imag;
  return z;  // we are allowed to return a single variable... now this single variable 
             // happens to contain multiple things, but it's still one variable!
}

// Read data from keyboard into a Complex structure (alternate)
void cget2(Complex& z) {
  cin >> z.real >> z.imag;
  // z is passed BY REFERENCE here, hence changes made by cget2 to 
  // its input z WILL change the corresponding variable in main.
  // Just like with scalar variables, using & after the input type
  // forces the variable to pass by reference (no copying -- function
  // uses the same memory locations as main for such variables).
}

// Formatted display of data in a Complex structure
void cdisplay(Complex z) {
  cout << z.real;
  if (z.imag > 0) {
    cout << "+" << z.imag << "j";
  }
  else if (z.imag < 0) {
    cout << z.imag << "j";   // remember that the minus sign is printed automatically here...
  }
  cout << endl;
}
