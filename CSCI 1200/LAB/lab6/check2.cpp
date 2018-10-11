#include<iostream>
#include<vector>
#include<list>
using namespace std;

void reverse_list(list<int>& l){
	list<int>::iterator l_itr=l.begin();
	list<int>::iterator l_itr2=l.end();
	l_itr2--;
	for(int i=0;i<int(l.size())/2;i++){
		int temp=*l_itr;
		*l_itr=*l_itr2;
		*l_itr2=temp;
		l_itr++;
		l_itr2--;
	}
}

void help(list<int> l){
	cout<<"size: "<<endl;
	cout<<l.size()<<endl;
	cout<<"values: "<<endl;
	list<int>::iterator i=l.begin();
	while(i!=l.end()){
		cout<<*i<<" ";
		i++;
	}
}

int main(){
	list<int> l1;
	for(int i=0;i<14;i++){
		l1.push_back(i);
	}
	help(l1);
	reverse_list(l1);
	cout<<endl;
	help(l1);
	cout<<endl;
	
	list<int> l2;
	l2.push_back(2);
	l2.push_back(3);
	help(l2);
	reverse_list(l2);
	cout<<endl;
	help(l2);
	
	return 0;
}