// ENME 202
// 8c_overloading_complex3.cpp
// Operator Overloading, part 3

// ALL operators have UNIQUE overloads.  Having defined, say, 
// operator* doesn't automatically give us *= capability!!  
// This is a separate operator which needs a separate overload


#include <iostream> 
using namespace std;

struct Complex {
  float a;  // Used to hold real part of complex number
  float b;  // Used to hold imag part of complex number
};

// Our previous overloads:
Complex operator+(Complex,Complex);
Complex operator*(Complex,Complex);
ostream& operator<<(ostream&,Complex);
istream& operator>>(istream&,Complex&);
Complex operator*(Complex,float);
Complex operator*(float,Complex);

// New overload for "*=":
Complex operator*=(Complex&, float);


int main(void) {

  Complex z, z1;
  Complex res;

  cout << "Enter real and imag parts of z: ";
  cin >> z;  // Converts to operator>>(cin,z)

  res = z*2; // Converts z*2 to operator*(z,2)
  cout << "z*2 = " << res << endl;  // Converts to operator<<(cout,res)

  res = 2*z;  // Converts 2*z to operator*(2,z)
  cout << "2*z = " << res << endl;

  // This now works too (thanks to the additional overload of operator*=)
  z *= 2; // Converts to operator*=(z,2)
  cout << "Now z=" << z << endl;

  // Done!
  return 0;
}

// New overload for Complex*=float
Complex operator*=(Complex& foo, float f) {
  foo.a = foo.a * f;
  foo.b = foo.b * f;
  return foo;
  // Why is foo passed by reference??
  // hint: think about what x*=2 is actually doing to x...
}

// Overload for float*Complex
Complex operator*(float bar, Complex foo) {
  Complex bas;
  bas.a = bar * foo.a;
  bas.b = bar * foo.b;
  return bas;
}

// Overload for Complex*float
Complex operator*(Complex foo, float bar) {
  Complex bas;
  bas.a = foo.a * bar;
  bas.b = foo.b * bar;
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
  bas.a = foo.a * bar.a - foo.b * bar.b;
  bas.b = foo.a * bar.b + bar.a * foo.b;
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




