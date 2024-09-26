// ENME 202
// 7a_structs.cpp
// Structured datatype (struct)

#include <iostream> 
using namespace std;

// A C++ struct is a compound data type made of
// of a collection of other data types.  
//
// A struct can contain as many different data components
// as desired, and they can be any mix of the basic 
// datatypes (int, float, etc) or other structs.

// Define a struct called "Complex" which will serve as a
// custom data type for storing complex numbers:
struct Complex {
  float real;  // real part of complex number
  float imag;  // imag part of complex number
};

// We can now declare variables of type Complex.
// A declared variable of type Complex is called an "instance" of
// the Complex struct.

// The internal variables within the struct are called 
// "member variables" (or, equivalently, "fields") of the struct.

// Note that it is convention to capitalize the 1st letter
// of the struct.

// Structs can be passed to functions just like any other
// data type.  Here are prototypes for functions to add and
// multiply complex numbers defined using the Complex struct:
Complex cadd(Complex, Complex);
Complex cmul(Complex, Complex); 

// Prototype for a function to display a complex value
void cdisplay(Complex);      


int main(void) {

  // Once the Complex struct has been defined, we can use it
  // to define variables with this structure, exactly as though
  // it were a built-in data type:
  Complex z1, z3, z4; // z2 initialized later...

  // Each Complex variable has two member variables that we
  // can access using a dot "." and between the instance name
  // and variable name:
  z1.real = -1;
  z1.imag = 5;
  cout << "z1 = -1 + 5j" << endl;

  // Fields of a structure can be initialized during declaration
  // very similarly to arrays.  Desired initial values are contained
  // in braces during the declaration.  These values are used to initialize
  // each field in the structure, in the order they are given in the 
  // structure definition.  Missing values for initialization will default
  // to zero, so long as at least one initial value is specified.
  Complex z2 = {0, 2.7};
  cout << "z2 = 2.7j" << endl;

  // Member variables are just like any other variable.  For
  // example we can assign a value from user input:
  cout << "Enter real and imag parts of z3: ";
  cin >> z3.real >> z3.imag;

  // We can also declare an array of type Complex:
  Complex cArray[3] = {z1, z2, z3};
  // We won't use cArray in this code...this is just to 
  // show that this step is allowed.

  // How much memory does an instance of Complex require?
  cout << "size of all member variables = ";
  cout << 2*sizeof(float) << endl;
  cout << "size of Complex = ";
  cout << sizeof(Complex) << endl;
  // Structs often require more memory than their member variables due
  // to padding by the compiler to avoid "memory alignment" issues.


  // Do the calculation z4 = z3*(z1+z2):
  z4 = cmul(z3, cadd(z1,z2));
  
  // Note: no intermediate variables needed, results
  // of each function has a single "natural" output (as opposed
  // to indirect output when using arrays), and as a consequence
  // the calls to different functions can be nested.

  // Show result of calculation:
  cout << "z4 = z3*(z1+z2) = ";
  cdisplay(z4);
}



void cdisplay(Complex z) {
  // Display a complex value to standard output
  cout << z.real;
  if (z.imag>0) {
    cout << "+" << z.imag << "j";
  }
  else if (z.imag<0) {
    cout << z.imag << "j";
  }
  cout << endl;
}


Complex cadd(Complex x, Complex y) {
  //  Function for doing z = x + y
  Complex z;

  // Implement rules of complex number addition
  z.real = x.real + y.real;
  z.imag = x.imag + y.imag;

  // A struct can be returned like any other variable:
  return z;

  // Remember that we are allowed to return a single value...
  // this particular value (z) happens to contain
  // multiple elements, but it's still a single variable!

  // As we will see shortly, a struct can instead be passed
  // by reference, allowing changes to z in the function to also
  // change the value in main().
}

Complex cmul(Complex x, Complex y) {
  //  Function for doing z = x * y
  Complex z;
  // Implement rules of complex number multiplication
  z.real = x.real*y.real - x.imag*y.imag;
  z.imag = x.real*y.imag + y.real*x.imag;
  return z;
}



