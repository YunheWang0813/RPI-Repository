#include<iostream>
#include<vector>
using namespace std;

void print_vec(vector<int>& v,unsigned int i){
	if(i<v.size()){
		cout<<i<<": "<<v[i]<<endl;
		print_vec(v,i+1);
	}
}

/*void print_vec(vector<int>& v){
	print_vec(v,0);
}*/

int main(){
	vector<int> a;
	a.push_back(3); a.push_back(5); a.push_back(11); a.push_back(17);
	print_vec(a,0);
}