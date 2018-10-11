#include<iostream>
#include<string>
#include<vector>
#include "superhero.h"
using namespace std;

ostream& operator<< (ostream& ostr, Superhero const& s){
	ostr<<"Superhero "<<s.getName()<<" has power "<<s.getPower()<<endl;
	return ostr;
}

bool operator> (const Superhero& s1, const Superhero& s2){
	if(s1.getPower()=="Fire"){
		if(s2.getPower()=="Wood"){
			return true;
		}
	}
	if(s1.getPower()=="Wood"){
		if(s2.getPower()=="Water"){
			return true;
		}
	}
	if(s1.getPower()=="Water"){
		if(s2.getPower()=="Fire"){
			return true;
		}
	}
	return false;
}