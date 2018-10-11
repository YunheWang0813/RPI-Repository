#include <iostream>
#include <vector>

int main(){
	int *d;
	int e[7]={15,6,-7,19,-1,3,22};
	d=e+e[5];
	std::cout<<*d;
	
	return 0;
}