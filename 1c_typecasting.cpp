// ENME202
// Variable types and typecasting

#include <iostream>
using namespace std;

int main(void) {

  /*
    Common C++ data types:
    ---------------------
    bool     - Boolean (true/false; 1 bit)
    char     - single text character
    int      - integer (16 or 32 bit depending on system)
    float    - single precision floating point (32 bit, usually)
    double   - double precision floating point (64 bit, usually)
    void     - lack of data type

    Other C++ data types to be aware of:
    --------------------
    unsigned int  - int >= 0, can have higher value than regular int
    short         - 16 bit int (to save memory)
    long          - 32 or 64 bit int (depending on system)
  */

  // Use sizeof() to find the number of bytes (8 bits) for a given data type:
  cout << "Size of bool : " << sizeof(bool) 
    << " byte" << endl; 
  cout << "Size of char : " << sizeof(char)  
    << " byte" << endl; 
  cout << "Size of int : " << sizeof(int) 
    << " bytes" << endl; 
  cout << "Size of short int : " << sizeof(short int)  
    << " bytes" << endl; 
  cout << "Size of long int : " << sizeof(long int)  
     << " bytes" << endl; 
  cout << "Size of unsigned long int : " << sizeof(unsigned long int)  
     << " bytes" << endl; 
  cout << "Size of float : " << sizeof(float)  
     << " bytes" << endl; 
  cout << "Size of double : " << sizeof(double)  
     << " bytes" << endl; 
  cout << "Size of wchar_t (wide char, for non-ascii char sets): " << sizeof(wchar_t)  
     << " bytes" << endl << endl; 

  // Declare an integer variable
  // (32 bit; from -(2^32/2)      to  +(2^32/2)-1
  //             = -2,147,483,648 to  2,147,483,647)
  int x;
  x = -2147483648;
  cout << "x = " << x << endl;

  // Declare a floating point variable
  // (32 bit; accurate to about 7 significant digits)
  float a;
  a = 2.54321;
  cout << "a = " << a << endl;

  // We can also give initial values to variables
  // when we declare them:
  float b = -2.1;

  // Can declare/initialize multiple initial values 
  // at the same time:
  float c = -2.5e3, d(1000); // c = -2500, d = 1000

  // We can change the value stored in a variable
  // at any time regardless of how the previous value
  // was generated (from calculation or initialization) 
  
  cout << "c = " << c << endl;
  c = d/c;
  cout << "Now c = " << c << endl;
  
  // We cannot change the variable type after it has been
  // declared.  This is known as "redeclaration"
  // and it is always an ERROR -- the code will not compile.
  //
  //   int c;   // This line would be an error here

  // However, we can CONVERT between variable types using
  // a technique called typecasting:

  cout << "a (float) typecast to an integer = " << (int)a << endl;
  
  cout << "5/4 without typecasting = " << 5/4 << endl;
  
  cout << "5/4 with typecasting = " << (float)5/(float)4 << "\n";


  // Initial variable values:
  //
  // There is NO guarantee in C++ that the initial value
  // stored in a variable is 0.  It MIGHT be, but it is
  // assible that initial values might be "garbage", i.e.
  // whatever happened to be initially stored in the memory
  // address assigned to the variable.
  // THERE IS NO GUARANTEED INITIALIZATION FOR ANY VARIABLE
  // IN C++.  If you need one, YOU have to provide it.
  

  // Remember: 
  // 
  // 1. arithmetic in C++ which involves ONLY integers is done
  //    using integer math, and hence ignores any decimal part of the
  //    result.  (Thus 9/5=1, 1/2=0, etc).  
  //
  // 2. In an assignment, the RHS of the expression is computed 
  //    first, then the resulting number is stored in the variable 
  //    name on the LHS.  As a result, "float a = 5/4" will result 
  //    in the value stored "a" having its decimal part truncated.
  //    This is true EVEN THOUGH the result of the calculation is 
  //    stored in a float! The (integer) arithmetic on the right of
  //    the = sign is done BEFORE the (integer) result is stored in
  //    the (float) variable on the left of the assignment operator (=). 

  return 0;

}