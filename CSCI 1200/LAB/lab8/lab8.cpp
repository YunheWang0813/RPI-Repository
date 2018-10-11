#include<iostream>
#include<vector>
#include<string>
using namespace std;

int countpaths(int x, int y){
	if(x==0||y==0){
		return 1;
	}
	
	return countpaths(x-1,y)+countpaths(x,y-1);
}

int main(){	
	cout<<countpaths(8,5)<<" "<<countpaths(1,2)<<" "<<countpaths(2,2)<<" "<<countpaths(3,3)<<endl;
	
	return 0;
}