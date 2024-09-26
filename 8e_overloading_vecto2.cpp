// ENME 202
// 8e_overloading_vector2.cpp
// Operator Overloading with a vector struct, part 2

#include <iostream>
#include <cmath>
using namespace std;

struct Vector3 {
  float x;        // Here we have replaced the array data with
  float y;        // separate x, y, z variables that can be
  float z;        // directly accessed using the dot notation
};

// Prototypes for Vector3 operations
float vecDot(Vector3,Vector3);
Vector3 vecCross(Vector3,Vector3);
float vecNorm(Vector3);

// Prototypes for overloaded operators
ostream& operator<<(ostream&,Vector3);
istream& operator>>(istream&,Vector3&);
Vector3 operator+(Vector3,Vector3);
Vector3 operator+(Vector3,float);

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

  v3 = v1+v2;  // Just like Matlab!!
  cout << endl << "v1 + v2 = " << v3 << endl;

  // v1+a gives result just like Matlab!
  cout << endl << v1 << " + " << a << " = " << v1+a << endl;

  v4 = vecCross(v1,v2);  // Matlab v4=cross(v1,v2);
  cout << endl << "v1 x v2 = " << v4 << endl;

  d = vecDot(v1,v2);  // Matlab: d = dot(v1,v2);
  cout << endl << "v1 . v2 = " << d << endl;

  m = vecNorm(v1);     // Matlab: m=norm(v1);
  cout << endl << "||v1|| = " << m << endl;

  cout << endl << "v1.y = " << v1.y << endl;

  v4 = v2;  // Same as in Matlab
  cout << endl << "After doing v4=v2:" << endl;
  cout << "  v4 = " << v4 << endl;

  v4.y = 3.14;
  cout << endl << "After doing v4[1]=3.14:" << endl;
  cout << "  v4 = " << v4 << endl;
  cout << "  v2 = " << v2 << endl;

  return 0;
}

// support function definitions
istream& operator>>(istream& i, Vector3& v) {
  // Read in the user-defined values for each element
  cin >> v.x >> v.y >> v.z;
  return i;
}

ostream& operator<<(ostream& o, Vector3 v) {
  o << "[ ";
  cout << v.x << " " << v.y << " " << v.z;
  o << "]";
  return o;
}

Vector3 operator+(Vector3 a, Vector3 b) {
  Vector3 res;
  res.x = a.x+b.x;
  res.y = a.y+b.y;
  res.z = a.z+b.z;
  return res;
}

Vector3 operator+(Vector3 a, float b) {
  // Do vector+scalar like Matlab does
  Vector3 res;
  res.x = a.x+b;
  res.y = a.y+b;
  res.z = a.z+b;
  return res;
}

float vecDot(Vector3 a, Vector3 b) {
  float res=0;
  res += a.x*b.x;
  res += a.y*b.y;
  res += a.z*b.z;
  return res;
}

// Always remember: any function can call any other function!
float vecNorm(Vector3 a) {
  return sqrt(vecDot(a,a));
}

Vector3 vecCross(Vector3 v, Vector3 w) {
  Vector3 res;  
  // Implement cross-product calculation
  res.x = v.y*w.z - v.z*w.y;
  res.y = v.z*w.x - v.x*w.z;
  res.z = v.x*w.y - v.y*w.x;
  return res;
}
