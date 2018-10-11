#include<iostream>
#include<vector>
#include<list>
using namespace std;

void reverse_vector(vector<int>& v){
	for(int i=0;i<int(v.size())/2;i++){
		int temp=v[i];
		v[i]=v[v.size()-1-i];
		v[v.size()-1-i]=temp;
	}
}

void help(vector<int> v){
	cout<<"size: "<<endl;
	cout<<v.size()<<endl;
	cout<<"values: "<<endl;
	for(int i=0;i<int(v.size());i++){
		cout<<v[i]<<" ";
	}
}

int main(){
	vector<int> v1;
	for(int i=0;i<100;i++){
		v1.push_back(i);
	}
	help(v1);
	reverse_vector(v1);
	cout<<endl;
	help(v1);
	cout<<endl;
	
	vector<int> v2;
	v2.push_back(2);
	v2.push_back(3);
	help(v2);
	reverse_vector(v2);
	cout<<endl;
	help(v2);
	
	return 0;
}