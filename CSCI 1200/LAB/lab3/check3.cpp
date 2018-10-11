#include<iostream>
#include<cstdlib>
#include"Time.h"
#include"dummy.cpp"
using namespace std;

void change_times(Time t1,Time &t2){
	
	t1.sethour(t1.gethour()+1);
	t2.sethour(t2.gethour()+1);
	print_stack();
}

int main(){
	cout<<sizeof(Time)<<endl;
	
	Time time1(3,5,5);
	Time time2(5,6,33);
	
	label_stack((uintptr_t*)&time1,"t1");
	label_stack((uintptr_t*)&time2,"t2");
	print_stack();
	change_times(time1,time2);
	
	label_stack((uintptr_t*)&time1,"t1");
	label_stack((uintptr_t*)&time2,"t1");
	
	return 0;
}