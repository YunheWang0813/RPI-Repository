#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(){
	
	char temp=char('A'+2);
	int t1=int(temp);
	int t2=int(char('a'+2));
	
	cout<<int(char('Z'))<<" "<<t1-t2<<endl;
	
	return 0;
}