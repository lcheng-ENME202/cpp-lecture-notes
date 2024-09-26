// ENME202
// Namespaces and variable scope

#include <iostream> 
using namespace std; 
  
// Declare a namespace and define a variable
namespace ns { 
    int x = 1; // local to ns
} 
  
int main() { 
    int x = 2;     // local to main()

    cout << ns::x << '\n';  
    cout << x << '\n';  
  
    return 0; 
} 

