// ENME 202 / ENAE 202
// 9b_class_inheritance.cpp

// Topics:
//  - inheretance
//  - destructors

#include <cmath>
#include <iostream>
using namespace std;

// Complex class from the last code file:
class Complex {
public:
  float a; // real part
  float b; // imag part
};

// Last time we created different versions of this class,
// each containing an extension of the original class.
// A better way to do this is using inheritance.
// Inheritance implements an "is a" relationship: if we
// have a Vehicle class, a Car class would inherit from
// Vehicle, and a Sedan class would inherit from Car
// (a sedan *is a* car, and a car *is a* vehicle).
//
// Consider our prior class that took the base Complex class
// but added a constructor to ask the user to define the
// real and imaginary values, and a method to
// calculate the phase angle. This new class *is a* Complex
// element, but with additional features, and thus we should
// think about defining the new class (let's call it
// Complex2 here) by inheriting from Complex as the
// so-called "base class" or "parent class".  Complex2
// is then a "derived class" or "child class":

class Complex2 : public Complex {
public:
  Complex2() { // Constructor
    cout << "Real: ";
    cin >> a;
    cout << "Imag: ";
    cin >> b;
  }
  float phase() { // class method to find phase angle
    return (atan2(b, a));
  }
};

// Because Complex2 inherits from Complex, we do not need
// to define the a and b variables for Complex2. Any non-private
// attributes or methods associated with Complex are automatically
// part of Complex2 due to inheritance.

// Inheritance is defined using the following syntax:
//
//   class derived_class: access_specifier base_class
//
// where access_specifier is either public, protected,
// or private.  If access_specifier is omitted then
// it defaults to private.
//
// Here is a summary of the different access types:
//
// Access         public   protected  private
// Same class       yes       yes       yes
// Derives classes  yes       yes       no
// Outside classes  yes       no        no
//
//
// We can also inherit from multiple classes:
//
//   class derived_class: access_specifier base_class1 base_class2 ...

// Classes also support destructors, which is a function that
// is called automatically when the object goes out of
// scope (due to the end of a function or other block).
//
// The destructor will also be executed when the delete operator
// is called on the object. Remember that delete can only be used
// on a pointer, so in this case, we must declare a _pointer_ to
// the class instance.
//
// When working with a pointer to an object, class attributes and
// methods are accessed with "->" instead of "." (see main()
// for an example)
//
// Here is a new Complex3 class that includes a destructor:

class Complex3 {
public:
  float a, b;
  Complex3(float a_, float b_) { // Constructor w/ 2 arguments
    a = a_;
    b = b_;
  }
  Complex3() { // Constructor w/o arguments
    a = 0;
    b = 0;
  }
  ~Complex3() { // Destructor
    cout << "Deleting (" << a << "," << b << ")\n";
  }
  void display() { // class method to find phase angle
    cout << a;
    if (b >= 0)
      cout << "+";
    cout << b << "j\n";
  }
};

// In this example, the Complex3 destructor simply reports
// that the instance has been deleted.
//
// Also note that this example has 2 constructors!  We can define
// what happens during instantiation depending on what arguments
// are used when declaring the object.

int main(void) {

  // Complex2 constructor queries user for values:
  Complex2 z;
  cout << z.a << " + j(" << z.b << ")" << endl;
  cout << "Phase angle = " << z.phase() << endl;

  // Try dynamic memory allocation:
  Complex3 *zz = new Complex3(9, 4.1);
  cout << "New Complex3 object created: ";
  zz->display(); // use -> syntax to access class method

  cout << endl;

  // Destructor called automatically when falling out of scope:
  for (int i = 0; i < 3; i++) {
    Complex3 zzz(i, i + 1); // zzz is local to each iteration!
    zzz.display();
  }

  cout << endl;

  // Need to manually delete the Complex3 pointer created earlier:
  delete zz; // manually call the destructor

  return 0;
}
