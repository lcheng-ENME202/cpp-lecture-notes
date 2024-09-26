// ENME 202
// 5d_bubbleSort.cpp
// Example: bubble sorting

#include <iostream>
using namespace std;

void bubbleSort(float*, int);
void fillRandArray(float*, int);
void displayArray(float*, int);

int main(void) {

  srand(time(NULL));
  int n = rand()%10 + 5;  // random array size from 5-14

  float* a = new float[n];  // allocate memory for array dynamically

  fillRandArray(a,n);       // fill array a with n random floats from 0-10

  cout << "Unsorted: \n";
  displayArray(a,n);  

  bubbleSort(a,n);  // pass the array pointer (a) and # of elements (n)
  
  cout << "\n\nSorted: \n";
  displayArray(a,n);  
  
  return 0;
}

// Bubble sort
//
// repeatedly step through the array, comparing each pair of adjacent
// items, swapping them if array[i] < arrayt[i-1].  
// repeat the loop until no swaps are needed.
// This is NOT the most efficient sorting method (there are many!) but
// it is simple to implement:
void bubbleSort(float* a, int n) {
  int done=0;
  while (!done) {  // repeat until no swaps have been made
    done=1;
    //  loop through the array, swapping neighbors as appropriate
    for (int i=1; i<n; i++) {
      if ( a[i] < a[i-1] ) {
        float tmp = a[i] ;
        a[i] = a[i-1] ;
        a[i-1] = tmp ;
        done=0;
      }
    }
  }
}

void fillRandArray(float* a, int n) {
  for (int i=0; i<n; i++) {
    a[i] = 10 * (float)rand()/(float)RAND_MAX;   // random float from 0-10
  }
}

void displayArray(float* a, int n) {
  cout << "[ ";
  for (int i=0; i<n; i++) {
    cout << a[i] << "  ";
  }
  cout << "]" << endl;
}