// ENME202
// 2a_if_else.cpp
// if() / elseif() / else()

#include <iostream>
using namespace std;

int main(void) {

  float c;
  cout << "Enter a float: ";
  cin >> c;

  /* 
    if (boolean_expression) {
      // do something
    }
    else if (boolean_expression) {
      // do something else
    }
    else {
      // do the other thing
    }

    The boolean expression MUST be enclosed in parentheses (recall
    this was optional in Matlab).

    Curly braces {} are used to denote the blocks of code
    which correspond to each of the possible branches (replaces
    Matlab's "end" statement).

    Note: braces in a conditional are OPTIONAL when there is
    only one statement in the corresponding branch.
  */

  if (c>0) {
    cout << c << " is a positive number." << endl;
  }
  else if (c<0) {
    cout << c << " is a negative number";
    if (c == -1) {
       cout << " and is equal to -1";
    }
    cout << "." << endl;
  }
  else {
    cout << c << " is exactly equal to zero." << endl;
    cout << "What are the odds of that?!" << endl;
  }

  cout << endl;

  /* 
    Just like in Matlab, only one of the "branches" of the
    conditional will be executed, depending on the value 
    entered for c.  Also like Matlab, C++ evaluates the cases in 
    the order they are given, starting at the top, and executes 
    the first block which is true.  All other cases are then 
    skipped.  If no cases are true, and no "else" clause is given,
    then NONE of the statements in the conditional are executed.
  */


  /* 
    Logical comparisons:
      a == b      equal
      a != b      not equal (vs. ~= in Matlab)
      >  /  >=    greater than / or equal
      <  /  <=    less than / or equal

    Logical operators:
      &&        AND
      ||        OR
      !         NOT (vs. ~ in Matlab)

     There are 3 key differences with Matlab:
     1. The C++ NOT operator is ! (vs. ~ in Matlab).
     2. For Matlab, & and | are also logical operators, without
        short circuiting, but in C++ these are *bitwise* operators.
        This means that "1 & 2" will evaluate to 1 in Matlab,
        but will be 0 in C++ (do you see why?). 
     3. There is no XOR logical operator in C/C++. There is, however, 
        a bitwise XOR defined by the caret symbol (^) that
        behaves the same way as the xor() function in Matlab.
  */

  int v;
  cout << "Enter an int: ";
  cin >> v;

  // AND example:
  cout << v << ">5 && " << v << "<10 = " << (v>5 && v<10) << endl; 

  // OR example:
  cout << v << "==3 || " << v << "<0 = " << (v==3 || v<0) << endl;   

  cout << endl;



  /*
    Below is an example that puts everything together
  */

  float cmin,cmax,x;   // declare all needed variables

  // Ask user to define a start and end of a number range:
  cout << "Enter the start and end of the range: ";
  cin >> cmin >> cmax;

  cout << "Enter a number: ";
  cin >> x;

  // Conditional below decides if x is outside, inside,
  // or on the boundary of the range [cmin,cmax].
  cout << x;     // display the value
  if ( (x>cmin) && (x<cmax) ) {   // is value inside the range?
    cout << " is inside";
  }
  else if ( (x<cmin) || (x>cmax) ) {
    cout << " is outside";
  }
  else {
    cout << " is on the ";
    if (x != 0) {
      cout << " (non-zero)";
    }
    cout << "boundary of";
  }
  cout << " the interval [" << cmin << "," << cmax << "]"<<endl;


  return 0;

}

