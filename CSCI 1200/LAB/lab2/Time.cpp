#include<iostream>
#include<string>
#include"Time.h"
using namespace std;

Time::Time(){
	hour=0;
	min=0;
	sec=0;
}

Time::Time(int aHour,int aMin,int aSec){
	hour=aHour;
	min=aMin;
	sec=aSec;
}

int Time::gethour() const{
	return hour;
}

int Time::getmin() const{
	return min;
}

int Time::getsec() const{
	return sec;
}

void Time::sethour(int h){
	hour=h;
}

void Time::setmin(int m){
	min=m;
}

void Time::setsec(int s){
	sec=s;
}

void Time::print(Time &time2) const{
	string ampm="am";
	int h=time2.gethour();
	int m=time2.getmin();
	int s=time2.getsec();
	if(h>12){
		h-=12;
		ampm="pm";
	}

	if(m<10&&s>=10){
		cout<<h<<":"<<"0"<<m<<":"<<s<<ampm;
	}
	if(m>=10&&s<10){
		cout<<h<<":"<<m<<":"<<"0"<<s<<ampm;
	}
	if(m>=10&&s>=10){
		cout<<h<<":"<<m<<":"<<s<<ampm;
	}
	if(m<10&&s<10){
		cout<<h<<":"<<"0"<<m<<":"<<"0"<<s<<ampm;
	}
	
}