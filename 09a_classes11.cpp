// ENME 202 / ENAE 202
// 7a_classes.cpp

#include <iostream>
using namespace std;

// A C++ class is a compound data type made of
// of a collection of other data types, and functions (called methods which
// operate on the data.
//
// A class can contain as many different data components
// as desired, and they can be any mix of the basic
// datatypes (int, float, etc) or other classes.

// Define a class called "Complex" which will serve as a
// custom data type for storing complex numbers:
class Complex {
public:
  // First let us put some member variables with datatypes
  float real; // real part of complex number
  float imag; // imag part of complex number

  // Classes can be passed to functions just like any other
  // data type. Here are prototypes for member functions (methods) to add and
  // multiply complex numbers defined using the Complex class:
  Complex cadd(Complex); // function prototype, adds to current object
  Complex cmul(Complex); // multiplies with current object
};

// We can now declare variables of type Complex.
// A declared variable of type Complex is called an "instance" or object of
// the Complex class.

// The internal variables within the class are called
// "member variables" (or, equivalently, "fields") of the class.

// Note that it is convention to capitalize the 1st letter
// of the class.

// Prototype for a function to display a complex value (note this is not a
// member function or method, but an external function - this is allowed too)
void cdisplay(Complex);

int main(void) {
  // Once the Complex class has been defined, we can use it
  // to define variables with this class, exactly as though
  // it were a built-in data type:
  Complex z1, z3, z4; // z2 initialized later...

  // Each Complex variable has two member variables that we
  // can access using a dot "." and between the instance name
  // and variable name:
  z1.real = -1;
  z1.imag = 5;
  cout << "z1 = -1 + 5j" << endl;

  // Fields of a class can be initialized during declaration
  // very similarly to arrays.  Desired initial values are contained
  // in braces during the declaration.  These values are used to initialize
  // each field in the class, in the order they are given in the
  // class definition.  Missing values for initialization will default
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
  cout << 2 * sizeof(float) << endl;
  cout << "size of Complex = ";
  cout << sizeof(Complex) << endl;
  // classes often require more memory than their member variables due
  // to padding by the compiler to avoid "memory alignment" issues.

  // Do the calculation z4 = z3*(z1+z2):
  // IMPORTANT: note how member functions are called with the dot operator
  z4 = z3.cmul(z1.cadd(z2));

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
  if (z.imag > 0) {
    cout << "+" << z.imag << "j";
  } else if (z.imag < 0) {
    cout << z.imag << "j";
  }
  cout << endl;
}

Complex Complex::cadd(Complex y) {
  //  Function for doing z = x + y
  Complex z;

  // Implement rules of complex number addition
  z.real = real + y.real; //real refers to real part of object on which this member function is called
  z.imag = imag + y.imag; // same with imag

  // A class can be returned like any other variable:
  return z;

  // Remember that we are allowed to return a single value...
  // this particular value (z) happens to contain
  // multiple elements, but it's still a single variable!

  // As we will see shortly, a class can instead be passed
  // by reference, allowing changes to z in the function to also
  // change the value in main().
}

Complex Complex::cmul(Complex y) {
  //  Function for doing z = x * y
  Complex z;
  // Implement rules of complex number multiplication
  z.real = real * y.real - imag * y.imag;
  z.imag = real * y.imag + y.real * imag;
  return z;
}
