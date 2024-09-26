// ENME 202
// 5a_dynamic_memory.cpp
// Dynamic memory allocation

#include <iostream>
using namespace std;

// TOPICS:
//    - reference operator (&)
//    - pointers (*p)
//    - dereference operator (*)
//    - dynamic memory allocation (new)


// WARNING: this may be a confusing lecture.  Pay attention, ask
// for things to be repeated, and ask questions!


// Prototypes for 3 functions:
void setToFive(int);                  // pass a variable
void setToFiveWithPointer(int *);     // pass a pointer
void setToSixWithReference(int &);    // pass a reference

int main(void) {

  // --------------------------------------------------------------
  // Pointers (*p) and reference operator (&)
  // --------------------------------------------------------------

  // A declared variable's name is synonymous with its value:
  int x = 3;

  // Remember that we can check the number of bytes for a given
  // variable type using the sizeof() function:
  cout << "sizeof(int) = " << sizeof(int) << endl;
  cout << "sizeof(long) = " << sizeof(long) << endl;
  cout << "sizeof(float) = " << sizeof(float) << endl;
  cout << "sizeof(double) = " << sizeof(double) << endl;
  cout << "sizeof(bool) = " << sizeof(bool) << endl;
  cout << "sizeof(char) = " << sizeof(char) << "\n\n";

  // Since x is of type int, it's size is the same as
  // the int data type itself:
  cout << "sizeof(x) = " << sizeof(x) << "\n\n";


  // Every value lives at a memory address. The address is the starting
  // point where the value lives, and the total number of bytes allocated
  // to the value depends on its type (int, float, etc).
  //
  // The memory address where a variable is stored be accessed using the 
  // reference operator, &:
  cout << "x lives at memory address " << &x << endl;

  // A pointer is a variable that holds a memory address, i.e. it "points"
  // to the address.  A pointer can be assigned to the address where a value
  // lives. A pointer is declared by placing "*" before an identifier
  // (variable name) of a specific data type:
  int* xPointer;
  cout << "xPointer points to (arbitrary) memory address " << xPointer << endl;

  // When declared, xPointer points to an arbitrary memory location.
  // If we fail to change the location it points to, we are left with
  // a "dangling pointer".  This is very dangerous!
  //
  // We can set the memory address xPointer points to using
  // the reference operator applied to some existing variable:
  xPointer = &x;
  cout << "xPointer now points to the memory address for x: " << xPointer << "\n\n";

  // The pointer and variable are now linked in the sense that they
  // are both associated with the same memory address.

  // Alternately, we could declare a pointer and point it to a
  // variable's memory address in a single line:
  // int* xPointer = &x;

  // Finally, note that each pointer is itself a value (address)
  // that resides at some other memory address:
  cout << "xPointer = " << xPointer << endl;
  cout << "&xPointer = " << &xPointer << "\n\n";

  // Since the *value* of a pointer is a memory address, its size is
  // the size required to store an address value, e.g. 8 bytes for
  // a 64-bit system:
  cout << "sizeof(xPointer) = " << sizeof(xPointer) << endl;

  // --------------------------------------------------------------
  // Dynamic memory allocation using "new"
  // --------------------------------------------------------------

  // We can create a pointer to set aside
  // heap memory at the location being pointed to using the 
  // "new" operator:
  int* yPointer = new int;

  // This step is called "dynamic memory allocation", because the 
  // memory is set aside at run-time rather than being pre-determined
  // at compile-time.

  // --------------------------------------------------------------
  // Dereference operator (*)
  // --------------------------------------------------------------

  // The value at the memory address pointed to can be accessed with the
  // dereference operator, *.

  // The dereference operator can be used to both get the value and
  // set the value at the given address:
  *yPointer = 999;    // set the value
  cout << "The value in the address pointed to by yPointer is ";
  cout <<  *yPointer << "\n\n";   // get the value

  // Using the dereference operator to change the value at an address
  // associated with a named variable also works:
  *xPointer = 4;
  cout << "After '*xPointer = 4' the value is now x = " << x << "\n\n";

  // Dereferencing can also be used to access specific elements
  // of an array:
  int v[4] = {8, 4, 2, 5};
  cout << "v[2] = *(v+2) = " << *(v+2) << "\n\n";

  // So, the asterisk operator * has two meanings:
  //   (1) to declare a pointer (int* nPointer)
  //   (2) to access the value a pointer points to (*nPointer = 4)
  //
  // This can be a bit confusing at first, so be careful!!


  // --------------------------------------------------------------
  // Why use pointers?
  // --------------------------------------------------------------

  // In C++, variables are passed to a function by value. When calling a
  // function with an argument, a new variable is instantiated internally and
  // assigned the value passed in the function call.  Any modifications to the
  // value inside the function are performed to this new (local) variable; the
  // variable that was invoked with the function call remains unchanged.
  x = 0;
  cout << "Start with x = 0\n";
  setToFive(x);
  cout << "The value of x is " << x;
  cout << " -- setToFive(x) did not modify x.\n";

  // A function can be written to perform the same task but instead accept a
  // pointer as the argument. This lowers the memory footprint of the program.
  // Unnecessary duplicate variables aren't created. The function can modify
  // the variable's value directly. Any modifications to the variable in the
  // function also affect the variable in the scope of the calling function.
  x = 3;
  setToFiveWithPointer(&x);
  cout << "The value of x is " << x;
  cout << " -- setToFiveWithPointer(&x) modified x.\n";

  // We can also pass our existing pointer to &x for the same result:
  x = 3;
  setToFiveWithPointer(xPointer);
  cout << "The value of x is " << x;
  cout << " -- setToFiveWithPointer(xPointer) modified x.\n";

  // Note that this is NOT the same thing as passing a variable by reference,
  // although the functionality is similar.  As a reminder,
  // in C++ (but not C), you can pass a variable by reference by defining 
  // the function's parameter like "int &x", and passing the variable itself. 
  // In this case any modifications to the variable inside the function will
  // also affect the variable inside the scope of the calling function
  x = 3;
  setToSixWithReference(x);
  cout << "The value of x is " << x;
  cout << " -- setToSixWithReference(x) modified x.\n\n";


  // Another important use for pointers is when we need to define
  // an array with a dynamic number of elements that cannot be determined
  // during the compile step.  In other words, the array size is only 
  // set after running the compiled code.  Examples include such 
  // cases as when the array size is set by user-defined input, a 
  // random number, or simply a variable.
  //
  // Random length example:
  srand(time(NULL));              // initialize random seed
  int randomsize = rand()%6 + 5;  // value (5 to 10) determined at runtime
  int* a = new int[randomsize];   // create an array of random length
  cout << "Elements in random length array:\n";
  for (int i=0; i<randomsize; i++) {
    a[i] = i;                     // set value
    cout << a[i] << " ";         // display value
  }


  // Recall that individual array elements can be referenced with 
  // brackets as usual, or by using the dereference operator:
  cout << "\n\n" << "a[5] = " << a[5] << endl;
  cout << "*(a+5) = " << *(a+5) << "\n\n";



  // --------------------------------------------------------------
  // Arrays are not pointers
  // --------------------------------------------------------------

  // First, it is important to note that we CANNOT find the size of a 
  // dynamically-allocated array -- sizeof(a)/sizeof(a[0]) will not work.
  // This is because a is just a pointer that has no idea how large the
  // array is.


  // The second issue is related, but more subtle.  Consider:
  int A[3] = {4,8,12};
  int* B = new int[3];
  // A is an array, with type "pointer to int", and
  // B is a pointer, with type "pointer to int".
  // but...
  // &A has type "pointer to int array", while
  // &B is simply the address where the pointer is stored.
  //
  // Because &A has type "pointer to int array", we can do the following:
  cout << "*A+1 = Value of A[0] + 1: " << *A+1 << endl;
  cout << "*(A+1) = Value of A[1]: " << *(A+1) << endl;
  cout << "A = Address of A[0]: " << A << endl;
  cout << "&A[0]+1 = Address of A[1]: " << &A[0]+1 << endl;
  cout << "A+1 = Address of A[1]: "<< A+1 << endl;
  cout << "&A+1 = Address after end of full array: " << &A+1 << endl;

  // The last few lines are key to remember.  For example, since &A has
  // type "pointer to int array", adding 1 to &A goes to the next
  // memory location after the END of the array, while adding
  // 1 to A yields the address of A[1].  If A were just a pointer
  // (and not an array) &A would instead show the memory address where
  // the pointer value is stored.

  // For an array, we cannot directly learn the address where the
  // value A is stored using the reference operator. Instead, A and &A
  // yield the same result:
  cout << "A =  " << A << "   (Address of A[0])\n";
  cout << "&A = " << &A << "   (Address of A[0])\n";
  // This is not the case for a pointer (dynamically-allocated array):
  cout << "B =  " << B << "   (Address of B[0])\n";
  cout << "&B = " << &B << "   (Address where pointer is stored)\n";



  // --------------------------------------------------------------
  // Releasing allocated memory
  // --------------------------------------------------------------

  // In the above examples, we created several pointers using the "new"
  // operator, i.e. using dynamic memory allocation to set aside
  // blocks of memory.  These blocks should be released once we are done 
  // using the pointers, otherwise the memory will remain unavailable
  // until the program exits.
  //
  // To avoid this, use the delete operator:
  delete[] a;         // delete[] an array pointer
  delete yPointer;    // delete a scalar pointer

  // Note that we do NOT need to delete xPointer since it was not
  // declared using dynamic memory allocation -- the memory space used
  // by static variables is automatically released when the scope of
  // declaration ends.


  // Beware dangling pointers -- this is a common cause of "memory leaks"
  // in C++.  Here is an example of what NOT to do:
  float* foo = new float[10];
  float* bar = new float[10];
  bar = foo;
  delete[] foo;  // this WILL release the memory for foo.
  delete[] bar;  // this will NOT release the memory originally 
                 // allocated for bar!  Memory leak!!  Some compilers
                 // will give a "double free" error since this code tries
                 // to use delete() on the same memory block twice.

  return(0);
}

void setToFive(int x_new) {                // pass a variable value (x)
  // called with: setToFive(x);
  x_new = 5;   // x in main() will NOT change
}
  
void setToFiveWithPointer(int *x_new) {    // pass a pointer to x
  // called with setToFiveWithPointer(*x);
  *x_new = 5;  // x in main() WILL change
}

void setToSixWithReference(int &x_new) {   // pass a reference to x
  // called with setToSixWithReference(x);
  x_new = 6;   // x in main() WILL change
}
