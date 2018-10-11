#include<iostream>
using namespace std;

int main(){
	int *apple;
	int banana[5]={1,5};
	apple=&banana[2];
	*apple=6;
	cout<<banana[2]<<endl;
	return 0;
}