#include<iostream>
#include<vector>
#include<string>
#include"print_stack.cpp"

int main(){
std::cout << "size of uintptr_t: " << sizeof(uintptr_t) << std::endl;
uintptr_t x = 72;
uintptr_t a[5] = {10, 11, 12, 13, 14};
uintptr_t *y = &x;
uintptr_t z = 98;
std::cout << "x address: " << &x << std::endl;
std::cout << "a address: " << &a << std::endl;
std::cout << "y address: " << &y << std::endl;
std::cout << "z address: " << &z << std::endl;
// label the addresses you want to examine on the stack
label_stack(&x,"x");
label_stack(&a[0],"a[0]");
label_stack(&a[4],"a[4]");
label_stack((uintptr_t*)&y,"y");
label_stack(&z,"z");
// print the range of the stack containing these addresses
print_stack();

return 0;
}