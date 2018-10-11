#include<iostream>
#include<vector>
#include<string>
using namespace std;

void compute_squares(int *array1,int *array2,int n){
	int p;
	for(p=0;p<n;p++){
		*(array2+p)=*(array1+p)* *(array1+p);
	}
}

int main(){
	int a[2];
	int b[2];
	a[0]=3,a[1]=4,a[2]=6;
	compute_squares(a,b,2);
	cout<<a[1]<<endl;
	cout<<b[1]<<endl;
}