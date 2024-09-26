// ENME202
// Standard template to start any basic C++ program


// Comment a line (or part of a line) with double-slash

/* 
  commment a block of
  text with slash-star ... star-slash
*/

#include <iostream>   // Required library for input/output stream operations

// A namespace defines the scope for identifiers (names of types, functions, 
// variables, etc), and are used to prevent name collisions that can occur
// when your code includes multiple libraries. The built in C++ library routines 
// are kept in the standard namespace ("std"), so it is common to explicitly
// use this namespace to avoid having to type "std::" in front of standard 
// identifiers:
using namespace std;

int main(void) {
	
  // Replace the main() block with actual code for your program.  

  // In the following code:
  //   "cin" is the "standard input" stream (the keyboard, by default)
  //   "cout" is the "standard output" stream (the screen, by default)
  //   ">>" is the "extraction operator" (extract from a stream)
  //   "<<" is the "insertion operator" (insert to a stream)
  //   "endl" means "end line" and is equivalent to the newline character ("\n")
  
  float a;                // declare a variable of type float
  cout << "Enter a value for \"a\": ";  // cout is "standard output"
  cin >> a ;              // "cin" is "standard input"
	cout << "3+a = " << 3+a;
	cout << endl;           
  
  // End of program code

  // Note that to output the double quotes, the backslash character
  // was inserted before each quote to tell the compiler to 
  // interpret the quote symbol literally, rather than as
  // the close of the string being sent to the cout stream.

  // In C++  the main function is of type int and thus
  // should return an integer value as the "exit status" of the code. 
  // Returning 0 tells the operating system there were no errors:
  return 0;
}