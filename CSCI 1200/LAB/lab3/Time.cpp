#include<iostream>
#include<string>
#include"Time.h"
using namespace std;

Time::Time(){
	hour=0;
	min=0;
	sec=0;
}

Time::Time(uintptr_t aHour,uintptr_t aMin,uintptr_t aSec){
	hour=aHour;
	min=aMin;
	sec=aSec;
}

uintptr_t Time::gethour() const{
	return hour;
}

uintptr_t Time::getmin() const{
	return min;
}

uintptr_t Time::getsec() const{
	return sec;
}

void Time::sethour(uintptr_t h){
	hour=h;
}

void Time::setmin(uintptr_t m){
	min=m;
}

void Time::setsec(uintptr_t s){
	sec=s;
}

void Time::print(Time &time2) const{
	string ampm="am";
	uintptr_t h=time2.gethour();
	uintptr_t m=time2.getmin();
	uintptr_t s=time2.getsec();
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