// ENME 202
// 4a_functions_basics.cpp
// Functions - the basics (1/2)

#include <iostream>
#include <cmath>
using namespace std;

// Functions in C++ programs must be DECLARED before use.
// Must declare: the function name, the type of its output,
// and the number and type of its inputs, in a format like so:

float avg(float, float);   // This is a function PROTOTYPE
// ^         ^      ^
// |         |      |
// |          --------- function will take 2 float arguments
// |
//  --- this is what the function will return

// The prototype (declaration) above says that avg() will be 
// a function returning a float number as its
// output, and taking two inputs which are both floats.

// The prototype must be given before the function
// is used.  It is convenient to do this before main() but after
// any #include statements.

// Note that the input/output variables are not named in the 
// function prototype.  Only the *type* of each input and output 
// needs to be specified.

int main(void) {

  float a,b,c;

  cout << "\nEnter two numbers: ";
  cin >> a >> b;

  // Pass values of a and b to avg(), and assign the result to c:
  c = avg(a,b);

  cout << "c = " << c <<endl;

  // The outputs of functions can also be directly displayed
  cout << "avg(a,b) = " << avg(a,b) << endl;
  
  // And you can nest functions, your own or the built-in ones:
  cout << "a+(b+sqrt(a))=" << avg(a,avg(b,sqrt(a))) << endl;

  // The nesting above is evaluated "inside-out" just like in Matlab:
  // first compute sqrt(a), then use that as the second input to avg()
  // with first input b, and finally use the result of that as the second
  // input to avg() with first input a.

  // Can pass numbers instead of (or with) variables, just like Matlab
  cout << "avg(-1," << b << ") = " << avg(-1,b) << endl;

  // Variable scope:
  //
  // Think of your main function as similar to the Matlab
  // "workspace".  Other C++ functions interact with your main 
  // function in exactly the same manner as Matlab functions interact
  // with the workspace.  
  // 
  // In particular, the idea that "what happens in a function stays 
  // in a function" applies.  Other functions CANNOT see variables in
  // main(), unless they are passed as inputs, and main() cannot see 
  // variables defined in other functions, unless those variables
  // are passed as outputs.

  return 0;

} // End of main()



// Define your functions AFTER main().  
// Here we define the avg() function:

float avg(float v1, float v2) {

  // Note that only the TYPE of the output is specified before
  // the function name, not the actual variable name used as output.
  // Both type *and* name are given for the input variables.

  // Input variables v1 and v2 are initialized to
  // whatever values are passed to the function when 
  // it is called.

  // The scope of any other variable declared in avg() are limited
  // to the function, and cannot be accessed within main().

  float v3 = (v1 + v2) / 2.0;

  // Value contained in the variable after "return"
  // is the output of the function
  return v3;

  // Can also directly return the result of any calculation
  // Thus, we could accomplish the same result with:
  //   return var1+var2;

}

// Each C++ function can have only ONE output, and the type of that 
// output must be declared.  A C++ function can have as many inputs 
// as desired, and their names and types must also be declared.  
//
// The output is NOT NAMED on the first line of a C++ function like 
// it is in Matlab.  Instead, a separate "return" statement at the 
// end of the function is used to define the specific value output 
// from the function.  Any variable defined and computed within the
// function can be returned as its output.
//
// So, what do we do when multiple values need to be returned?
//
// Here are 3 solutions (upcoming lecture topics):
//
// 1. pass *references* to variables defined in to the calling function, 
//    and modify these variables directly instead of returning an 
//    output.
//
// 2. use a data structure (struct) that contains multiple values
//
// 3. use an object (class instance) that contains multiple values
