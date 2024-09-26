// ENME 202
// 8d_overloading_vector.cpp
// Operator Overloading with a vector struct

#include <iostream>
#include <cmath>
using namespace std;

// "Wrap" 3 element array in a structure to get the 
// benefits of both
struct Vector3 {
  float xyz[3];     // Is this really the best way to represent the
                    // vector [x, y, z] inside the Vector3 struct?
                    // What is another way to do this?
};

// Prototypes for Vector3 operations
float vecDot(Vector3, Vector3);
Vector3 vecCross(Vector3, Vector3);
float vecNorm(Vector3);

// Prototypes for overloaded operators
ostream& operator<<(ostream&,Vector3);
istream& operator>>(istream&,Vector3&);
Vector3 operator+(Vector3,Vector3);
Vector3 operator+(Vector3,float); // Remember: NOT commutative

// main code 
int main(void) {
  Vector3 v1, v2, v3, v4;
  float a,d,m;
	
  cout << "Enter v1: ";
  cin >> v1;

  cout << "Enter v2: ";
  cin >> v2;

  cout << "Enter a scalar: ";
  cin >> a;

  v3 = v1+v2;  // Just like Matlab
  cout << endl << "v1 + v2 = " << v3 << endl;

  // v1+a gives result just like Matlab
  cout << endl << v1 << " + " << a << " = " << v1+a << endl;

  v4 = vecCross(v1,v2);  // Matlab v4=cross(v1,v2);
  cout << endl << "v1 x v2 = " << v4 << endl;

  d = vecDot(v1,v2);  // Matlab: d = dot(v1,v2);
  cout << endl << "v1 . v2 = " << d << endl;

  m = vecNorm(v1);     // Matlab: m=norm(v1);
  cout << endl << "||v1|| = " << m << endl;

  // Using structures and overloads results in MUCH more natural 
  // looking code then when we were forced to work directly with
  // native arrays!
  
  // Accessing the individual data elements of our vectors 
  // is a still little awkward though, since these are now
  // contained in the "xyz" field of the Vector3 structure

  cout << endl << "v1[1] = " << v1.xyz[1] << endl;

  // Hmmm...could we overload operator[] to make this look more natural?  
  // Actually yes! Do you know how to do it??
  
  // Copy v2 onto v4: can do this now without loops since the array is 
  // "wrapped" inside a structure!
  v4 = v2;  // Same as in Matlab
  cout << endl << "After doing v4=v2:" << endl;
  cout << "  v4 = " << v4 << endl;

  // Although v1,...,v4 are all Vector3 structs, they all use
  // different memory locations to store their associated data.
  // Changing one doesn't affect any of the others:
  v4.xyz[1] = 3.14;
  cout << endl << "After doing v4[1]=3.14:" << endl;
  cout << "  v4 = " << v4 << endl;
  cout << "  v2 = " << v2 << endl;
  
  return 0;
}

// support function definitions
istream& operator>>(istream& i, Vector3& v) {
  // Read in the user-defined values for each element
  for (int k=0;k<3;k++) i >> v.xyz[k];
  return i;
}

ostream& operator<<(ostream& o, Vector3 v) {
  o << "[ ";
  for (int i=0;i<3;i++) cout << v.xyz[i] << " ";
  o << "]";
  return o;
}

Vector3 operator+(Vector3 a, Vector3 b) {
  Vector3 res;
	for (int i=0;i<3;i++)
    res.xyz[i] = a.xyz[i]+b.xyz[i];
  return res;
}

Vector3 operator+(Vector3 a, float b) {
  // Do vector+scalar like Matlab does
  Vector3 res;
	for (int i=0;i<3;i++)
    res.xyz[i] = a.xyz[i]+b;
  return res;
}

float vecDot(Vector3 a, Vector3 b) {
  float res=0;
  for (int i=0;i<3;i++) res += a.xyz[i]*b.xyz[i];
  return res;
}

// Always remember: any function can call any other function!
float vecNorm(Vector3 a) {
  return sqrt(vecDot(a,a));
}

Vector3 vecCross(Vector3 v, Vector3 w) {
  Vector3 res;  
  // Implement cross-product calculation
  res.xyz[0] = v.xyz[1]*w.xyz[2] - v.xyz[2]*w.xyz[1];
  res.xyz[1] = v.xyz[2]*w.xyz[0] - v.xyz[0]*w.xyz[2];
  res.xyz[2] = v.xyz[0]*w.xyz[1] - v.xyz[1]*w.xyz[0];
  return res;
}



