#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

  // Course Grading:
  //   - the course grade will be curved
  //   - the lowest homework grade will be dropped automatically
  //   - for other questions/issues see me during office hours this week


  // Final Exam Format:
  //   - Monday, Nov. 18, 11 - 11:50 AM, 50 min
  //   - You are allowed one 3x5 inch index card, front and back, for notes, but no other materials are permitted. 
  //   - You may not use a calculator, phone, computer, or any other electronic device. 
  //   - You may not access a programming environment in any form. 
  //   - You may only have the exam, note card, and writing implement at hand. 
  //   - Only use commands and functions that we have covered in class; DO NOT use any commands that you may be familiar with from another source. 



  // EXAM TOPICS:
  

  // 1. C++ basics
  //  - declaring variables
  //  - syntax differences between Matlab and C++
  //  - specific operators (e.g. %)
  //  - type casting
  cout << (555 % (int)4.7) << endl;


  // 2. Basic input/output streams (cin, cout)
  float a, b;
  cout << "Prompt:\n" << endl;
  cin >> a >> b;
  
  
  // 3. Basic functions in <cmath>
  cout << endl << pow(1.5, 4) << endl;
  cout << sqrt(a) << endl;
  cout << sin(atan(cos(sqrt(pow(log(a),exp(-2)))))) << endl;
  
  
  // 4. Conditionals (if, else if, else)
  // 5. Logical values, comparisons, and Boolean operators (&&, ||, !, xor())
  int x=0, y=1, z=1;
  if ((x && y) || (z && !x)) {
    cout << "(x && y)||(z && !x) is true\n";
  }
  else if (x && !y) {
    cout << "will we get here? ";
    cout << "I don't think so.";
  }
  else 
    cout << "both ((x && y) || (z & !x)) and (x && !y) are false.";


  // 6. Arrays (initializing, overruns)
  int A[10];
  cout << "A[15] = " << A[15] << endl;
  
  // 7. Functions (function type, passing / returning values)
  
  // 8. Pointers, reference operator, dereference operator, 
  //    and Passing by reference
  //    - What exactly is a pointer?
  //    - What do we mean by "base address"?
  //    - What are the two ways "*" is used?
  //    - What are the two ways "&" is used?
  //    - Can we ever pass an array to a function?
  //    - Can we ever return an array from a function?
  //    - Arrays are not pointers, and pointers are not arrays,
  //      can you explain the difference?
  
  
  // 9. Dynamic memory allocation
  //  - why / when / how?
  //  - scalars vs. arrays:
  int* newScalarPointer = new int;
  int* newArrayPointer = new int[100];
  // Not responsible for delete command...
  

  // 10. Structs
  //   - declaring structs
  //   - why create a struct?  When would you want to do this?
  //   - how to access member variables of a struct (.)
  //   - how to declare & access member functions of a struct



  // 11. Overloading
  //   - overloading operators (+,-,*,/,+=,-=,*=,>>,<<)
  //   - overloading + does not also overload +=
  //   - different overloads for different argument types
  //     and orders
  //   - overloading regular functions (vs. operators)


  // 12. How to write code from a set of specifications!!


  /*
  You are NOT responsible for the following:
    - switch / case statements
    - <iomanip> library
    - File streams (no writing from scratch, but maybe interpretation)
    - classes / inheritance and object-oriented programming
  */  
  
  return 0;
  
}
