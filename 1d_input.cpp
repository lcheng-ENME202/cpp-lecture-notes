// ENME202
// 1d_input.cpp
// User input, shorthand operators

/* Topics:
      (1) input streams (cin)
      (2) shorthand operators (e.g. ++, +=)
      (3) modulo operator (%)
*/

#include <iostream>
using namespace std;

int main(void) {

  // Using the input stream (cin)

  // Declare some variables, and ask user to enter
  // their values:
  float a,b,c,d;
  cout << "Enter two numbers: ";
  cin >> a;  // read a value from the keyboard and assign it to a
  cin >> b;  // read another value and assign it to b
  cout << "You entered a=" << a << ", b=" << b << endl << endl;

  // We could also read in two or more values in a single statement
  // by "chaining" extraction operators:
  cout << "Enter two more numbers: ";
  cin >> c >> d;
  cout << "You entered c=" << c << ", d=" << d << endl << endl;

  // Any "white space" (space,tab,newline) is used by
  // cin to determine the boundaries between two 
  // (or more) numbers when reading from the keyboard.
  
  // cin will wait ("block") until ALL the numbers it
  // is expecting have been entered.  So in the above,
  // the program will not proceed past the cin lines
  // until numbers for both a and b (or c and d) have been entered.
  


  // Shorthand operators:
  //
  // C++ supports a range of shorthand operations that allow us
  // to do math operation on variables as part of a larger
  // statement.
  // Note the different outputs for prefix vs. postfix operations.
  // In a prefix operation, the math is done before the variable
  // value is used in the larger statement, while in a postfix
  // operation the value is used as-is, then the math is performed:
  cout << "Shorthand operators:" << endl;
  // a++ --> add 1 to a (same as a = a + 1) (postfix):
  cout << "a++ --> " << (a++) << endl;  
  // ++a --> add 1 to a (same as a = a + 1) (prefix):
  cout << "++a --> " << (++a) << endl;  
  // a-- --> subtract 1 from a (same as a = a - 1) (postfix):
  cout << "a-- --> " << (a--) << endl;  
  // a+=5 --> add 5 to a (same as a + a + 5):
  cout << "a+=5 -->" << (a+=5) << endl; 
  // a*=2 --> multiply a by 2 (same as a = a * 2):
  cout << "a*=2 -->" << (a*=2) << endl << endl; 

  // Note that these operations change the value of a (they do not
  // simply return a result!):

  a = 10, b=10;
  cout << a++ << "..." << a++ << "..." << a++ << endl;
  cout << a << endl;

  // Prefix vs. Postfix:
  a = 10, b=10;
  cout << "Prefix:  " << ((float)a / ++a) << endl;
  cout << "Postfix: " << ((float)b / b++) << endl;

  // Exponentiation:
  //
  // We DO NOT use ^ for exponentiation in C++
  // The caret symbol is instead used for bitwise xor
  // as in the below pseudo-code:
  //
  //  1^2 = xor(b01, b10) = b11 = decimal 3
  //
  // Instead, you'd need to do something like this:

  cout << "a^2 = " << a*a << endl << endl;

  // What about higher powers, roots, trig, etc
  // These require including a NEW LIBRARY (cmath)
  // that we will discuss soon



  // Modulo operator:
  //
  // Another mathematical operator that is very important
  // in programming is the "modulo" operator, denoted by %.
  // This is the same as the mod() function in Matlab.
  // Modulo returns the remainder from the division of
  // two integers:
  cout << "Modulo operator:" << endl;
  cout << "2%3 = " << (2 % 3) << endl;     // remainder = 2
  cout << "20%3 = " << (24 % 5) << endl;   // remainder = 4
  cout << "100/10 = " << (100 % 10) << endl; // remainder = 0

  int x, y;
  cout << "Enter integers x, y for x%y: ";
  cin >> x >> y;
  cout << x << "%" << y << " = " << x%y << "\n\n";

  return 0;

}
