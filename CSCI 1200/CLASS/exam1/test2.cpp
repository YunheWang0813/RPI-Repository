#include<iostream>
using namespace std;

int main(){
	int  x = 10;
	int& r = x;
	r=20;
	cout<<x<<endl;
	cout<<r<<endl;
	return 0;
}