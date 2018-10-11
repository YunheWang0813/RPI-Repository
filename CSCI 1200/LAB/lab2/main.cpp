#include<iostream>
#include"Time.h"
using namespace std;

int main(){
	cout<<"Please enter the current time"<<endl;
	cout<<"Provide the hour, minute and second"<<endl;
	int hour,min,sec;
	cin>>hour>>min>>sec;
	Time timenow(hour,min,sec);
	cout<<"The time now is ";
	timenow.print(timenow);
	cout<<endl;
}