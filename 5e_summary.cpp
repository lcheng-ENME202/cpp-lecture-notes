// ENME 202
// 5e_summary.cpp
// Summary of arrays vs. pointers

#include <iostream>
using namespace std;

int main(void) {

  // I. Scalar pointers:

  int* x = new int;   // allocate memory for an integer and 
                      // create pointer x pointing to base address
  cout << "\nScalar pointer x:" << endl << "---------------" << endl;
  *x = 999;           // place value into allocated memory
  cout << "x:     " << x << endl;     // pointer (value of x = address x points to)
  cout << "*x:    " << *x << endl;    // dereference pointer (value in memory x points to)
  cout << "&x:    " << &x << endl;    // reference pointer (address where x lives)
  cout << "*(&x): " << *(&x) << "\n\n"; // value in address of x (= x itself)
  

  // II. Arrays are not pointers:

  int y[5] = {1,2,3,4,5};
  
  cout << "Array y:" << endl << "---------------" << endl;
  cout << "size of array y = " << sizeof(y) << " bytes (" << 8*sizeof(y) << " bits)" << endl;
  cout << "y:     " << y << endl;     // address of y[0]
  cout << "*y:    " << *y << endl;    // value of y[0]
  cout << "&y:    " << &y << endl;    // address of y[0] -- different than a pointer!
  cout << "*(&y): " << *(&y) << "\n\n"; // same as &y -- NOT the value of y[0] as expected

  // y is of type "pointer to int" and &y is of type "pointer to int array".
  // This is why &y returns the same address as y, but *(&y) is not
  // the same as *y.
  

  // III. Dynamic memory allocation for an array creates a pointer (not an array):
  
  int* z = new int[5];
  z[0]=1; z[1]=2; z[2]=3; z[3]=4; z[4]=5;
  
  cout << "Array pointer z:" << endl << "---------------" << endl;
  cout << "size of pointer z = " << sizeof(z) << " bytes (" << 8*sizeof(z) << " bits)" << endl;
  cout << "z:     " << z << endl;     // address of z[0]
  cout << "*z:    " << *z << endl;    // value of z[0]
  cout << "&z:    " << &z << endl;    // address of z -- different than an array!
  cout << "*(&z): " << *(&z) << "\n\n"; // value in address of z (=z itself)
  
  return 0;
}