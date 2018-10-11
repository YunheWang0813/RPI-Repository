#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <cstdlib>    // library with the exit function


// Returns true if the candidate root is indeed a root of the polynomial a*x*x + b*x + c = 0 
bool check_root(int a, int b, int c, float root) {  
  // plug the value into the formula
  float check = a * root * root + b * root + c;
  // see if the absolute value is zero (within a small tolerance)
  if (fabs(check) > 0.0001) {
    std::cerr << "ERROR:  " << root << " is not a root of this formula." << std::endl;
    return false;
  } else {
    return true;
  }
}

/* Use the quadratic formula to find the two real roots of polynomial.   Returns 
true if the roots are real, returns false if the roots are imaginary.  If the roots 
are real, they are returned through the reference parameters root_pos and root_neg. */ 
bool find_roots(int a, int b, int c, float &root_1, float &root_2) {
  // compute the quantity under the radical of the quadratic formula
  int radical = b*b - 4*a*c;
  // if the radical is negative, the roots are imaginary
  if (radical < 0) {
    std::cerr << "ERROR:  Imaginary roots" << std::endl;
    return false;
  }
  float sqrt_radical = sqrt(radical);  
  // compute the two roots
  root_1 = (-b + sqrt_radical) / float(2*a);
  root_2 = (-b - sqrt_radical) / float(2*a);
  return true;
}

int main() {
  // We will loop until we are given a polynomial with real roots
    std::cout << "Enter coefficients to a quadratic function: x*x + b*x + c = 0 5 times" << std::endl;
    int my_b[5], my_c[5], i;
    float smaller_root[5];
    for(i=0;i<5;i++){
        std::cin >> my_b[i] >> my_c[i];
    // create a place to store the roots
        float root_1, root_2;
        bool success = find_roots(1,my_b[i],my_c[i], root_1,root_2);
    // If the polynomial has imaginary roots, skip the rest of this loop and start over
        if (!success){
            smaller_root[i]=0;
            std::cout<<"ERROR"<<std::endl;
            continue;}
        std::cout<<root_1<<" "<<root_2<<std::endl;
        if (root_1<root_2){
            smaller_root[i]=root_1;}
        else{
            smaller_root[i]=root_2;}
    }
    for(i=0;i<5;i++){
        std::cout<<i+1<<"  "<<smaller_root[i]<<std::endl;}
  // by convention, main should return zero when the program finishes normally 
return (0);
}
