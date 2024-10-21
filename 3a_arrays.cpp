// ENME 202
// 3a_arrays.cpp
// C++ Arrays - overview

#include <iostream>
#include <cmath>
using namespace std;

int main(void) {

  // Must declare type and length of arrays in C++

  float v1[3], v2[3], v3[3];  // Declare 3-element arrays of floats
  
  int w[4];    // Declare 4-element array of integers, length(w), size(w)
  
  // The array lengths for v1, v2, v3, and w are fixed.  
  // Finding the length of an existing array takes some work. 
  // C++ does not have a simple length() or size() function
  // like Matlab.  Instead, we must calculate the array length
  // by looking at the number of bytes of memory the array
  // takes up, and divide by the number of bytes for a single
  // element of the array.  This can be done using the sizeof()
  // function, which returns the number of bytes occupied by
  // the function argument:
  cout << "Array w takes up " << sizeof(w) << " bytes. \n";
  cout << "w[0] takes up " << sizeof(w[0]) << " bytes. \n";
  int w_length = sizeof(w)/sizeof(w[0]);
  cout << "Thus the array has " << w_length << " elements. \n\n";

  // Advanced concept: 
  // Another way to extract the array length uses the concept
  // of "pointers", which we will talk about soon.  The following
  // syntax will yield the same value for w_length as above:
  //
  w_length = *(&w + 1) - w;   // don't worry about this yet!
  cout << "w_length = " << w_length << " elements \n";
  

   
  // Note that in C++, array indices start at 0 (unlike Matlab, 
  // where indices start at 1). Thus v1 contains three elements
  // defined by v1[0], v1[1], v1[2].

  // Just like regular variables, arrays are not initialized
  // to 0.  Their initial contents may be "garbage":
  cout << "Initial values of w = ";
  cout << w[0] << "," << w[1] << "," << w[2] << "," << w[3];
  cout << endl << endl;

  // Note: the first element of a C++ array is numbered 0
  // the last element of a C++ array is n-1, where n is
  // the length of the array.  Square brackets, as opposed
  // to parentheses are used to specify the index.

  // Each element of an array is an ordinary
  // variable, where you can store numbers
  // or the results of calculations
  cout << "Enter 3 components of v1: ";
  cin >> v1[0] >> v1[1] >> v1[2]; 

  // Unlike Matlab, you CANNOT "read" an entire array from
  // the keyboard at once.  This line would be an ERROR
  // and the program will not compile:
  // cin >> v1;

  // The only way to "load" an array using keyboard data
  // is to manually assign each number read to a different position
  // in the array.  For this reason, "for" loops and arrays are 
  // usually constant companions in C++:
  cout << "Enter 3 components of v2: ";
  for (int i=0; i<3; i++) {
    cin >> v2[i];
  }
  
  // Such loops are very useful for reading in, 
  // printing out, or doing calculations with 
  // a range of array elements.
  
  // C++ has no native ability to add, subtract, multiply
  // etc arrays.  UNLIKE MATLAB, ARRAYS IN C++ ARE JUST BIG
  // LISTS OF NUMBERS.  They have no mathematical properties
  // themselves; you can only work with the individual numbers
  // they contain.

  // Thus, to do the kind of array calculations we've done in Matlab,
  // you have to manually work with the individual elements of each array
   
  // Matlab's v3 = v1 + v2 would need to be done in C++ like so:
  for (int i=0; i<3; i++) {
    v3[i] = v1[i]+v2[i];
  }

  // and to then actually display the result for v3, we have 
  // to explicitly send each element it contains to the screen:
  cout << endl << "v1+v2 = ";
  for (int i=0; i<3; i++) {
    cout << v3[i] << " ";
  }
  cout << endl;
  
  // Similarly, unlike Matlab C++ math functions cannot work on arrays. 
  // Instead you must do the element-by-element operations 
  // by hand:
  
  // Equivalent to Matlab's v3=sin(v2)
  for (int i=0; i<3; i++) {
    v3[i] = sin(v2[i]);
  }
  // Next display result:
  cout << "\nsin(v2) =\n";
  for (int i=0; i<3; i++) {
    cout << v3[i] << endl;
  }
  cout << endl; 
  
  // Note that C++ arrays have no concept of "orientation".
  // Whether they are displayed horizontally or vertically is
  // up to you (whether you print out an endl between each element
  // or just a space.)
  
  // Finally, you CANNOT display all the elements of an array
  // by sending it to the screen (well, you can try,
  // but you won't get what you expect!)  A loop like the
  // above is the only way to display the contents of an
  // array.
  
  cout << "v3 = " << v3 << "\n\n";

  // Huh?  What is the deal with that?  What gets displayed?


  // Now, what happens if we accidently go "past the end" of an array?
  // Maximum valid index for arrays v2 and v3 should be 2
  // since they are declared as length 3 arrays.

  for (int i=0; i<5; i++) {
    v3[i] = cos(v2[i]);  // v2[3] and v2[4] don't exist?
  }
  cout << "cos(v2) =";
  for (int i=0; i<5; i++) {
    cout << " " << v3[i]; 
  }

  // Hmmm...what about negative indices?

  cout << "\n\n" << "v3[-i] = " ;
  for (int i=0; i<10; i++) {
    cout << v3[-i] << " ";
  }
  cout << endl;

  // Ooops -- looks like we overshot the end of the arrays 
  // in both loops above.  But our code compiled and ran
  // just fine. . .?
  //
  // Yes, C++ will happily let us work with array elements "past the end"
  // of the arrays we declare.  This is known as an "array overrun".
  //
  // C++ DOES NOT CHECK BOUNDS when working with arrays; that is, it
  // does not check whether an array index is valid like Matlab does.
  // You can specify negative indices, and indices beyond the declared 
  // end of the array.  
  //
  // There are specific reasons for this (it can be useful behavior
  // in advanced programming), but it can be VERY DANGEROUS, especially 
  // for the kinds of numerical programming we are doing.  
  //
  // Array overruns a big source of errors ("bugs") in C++. 
  // You will likely create an array overrun bug at least 
  // once in this course, so be on the lookout! 

  // Finally, note that a simple way to avoid array overruns is to
  // use the actual array length when defining the loop boundaries.
  //
  // Recall that sizeof() returns the number of bytes assigned to
  // a data element, so given an array a, sizeof(a) will return
  // the total number of bytes allocated to the array, while
  // sizeof(a[0]) will return the numnber of bytes allocated to
  // just the first element of the array. Using this, we can
  // find the number of array elements as sizeof(a)/sizeof(a[0]):   

  srand(time(NULL));  // initialize random seed using time (in seconds)
  int a[rand()%12+1];   // create an array of random length (up to 12)
  for (int i=0; i<sizeof(a)/sizeof(a[0]); i++) {
    cout << i << endl;
  }

  // WARNING!  The above code is NOT compliant with C++ standards,
  // and may not operate correctly in some compilers (and should NOT
  // be used in practice!!).  The number of elements in the array
  // MUST be known when the code is compiled, which is not the case
  // here.  To declare an array with a number of elements that is 
  // not defined until "run time", we must use pointers:
  //
  //    int a[rand()%12];   -->   int* a = new int[rand()%12];
  //
  // This is a more advanced concept that will discuss this 
  // shortly under the topic of dynamic memory 

  

  return 0;
}
