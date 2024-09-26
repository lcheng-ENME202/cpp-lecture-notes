// ENME 202
// 8b_overloading_complex2.cpp
// Operator Overloading, part 2

// Overloaded operators can be defined to do different things
// when different variable types are involved.

#include <iostream> 
using namespace std;

struct Complex {
  float a;  // Used to hold real part of complex number
  float b;  // Used to hold imag part of complex number
};


// Previous overloads:
Complex operator+(Complex,Complex);
Complex operator*(Complex,Complex);
ostream& operator<<(ostream&,Complex);
istream& operator>>(istream&,Complex&);

// New overload for Complex * float:
Complex operator*(Complex,float);


int main(void) {

  Complex z;
  Complex res;

  cout << "Enter real and imag parts of z: ";
  cin >> z;    // Converts to operator>>(cin,z)

  res = z*2.5; // Converts z*2.5 to operator*(z,2.5)
  cout << "z*2.5 = " << res << endl;    // Converts to operator<<(cout,res)

  // Now, what about:
  cout << "2.5*z = " << 2.5*z << endl;  // Converts 2.5*z to operator*(2.5,z)
  // This won't work, since we have not overloaded 
  // any "float*Complex" operator.
  // C++ does not assume commutation!

  return 0;
}

// New overload for Complex*float
Complex operator*(Complex foo, float f) {
  Complex bas;
  bas.a = foo.a * f;
  bas.b = foo.b * f;
  return bas;
}

Complex operator+(Complex foo, Complex bar) {
  Complex bas;
  // Implement rules of complex number addition
  bas.a = foo.a + bar.a;
  bas.b = foo.b + bar.b;
  return bas;
}

Complex operator*(Complex foo, Complex bar) {
  Complex bas;
  // Implement rules of complex number multiplication
  bas.a = foo.a*bar.a-foo.b*bar.b;
  bas.b = foo.a*bar.b+bar.a*foo.b;
  return bas;
}

ostream& operator<<(ostream& o, Complex z) {
  o << z.a;
  if (z.b>0) {
    o << "+" << z.b << "j";
  }
  else if (z.b<0) {
    o << z.b << "j";
  }
  return o;
}

istream& operator>>(istream& i, Complex& z) {
  i >> z.a >> z.b;
  return i;
}


