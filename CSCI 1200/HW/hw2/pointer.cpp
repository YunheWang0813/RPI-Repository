#include <iostream>

int main() {
  float x=5, y=9;
  float *p = &x, *q = &y;
  *p = 17.0;
  *q = *p;
  q = p;
  *q = 13.0;

  std::cout << "x = " << x << std::endl;
  std::cout << "y = " << y << std::endl;
  std::cout << "p = " << p << std::endl;
  std::cout << "q = " << q << std::endl;
  std::cout << "*p = " << *p << std::endl;
  std::cout << "*q = " << *q << std::endl;

  return 0;
}