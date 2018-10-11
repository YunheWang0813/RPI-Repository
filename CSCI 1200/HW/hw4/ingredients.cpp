#include<iostream>
#include<list>
#include<string>
#include"ingredients.h"
using namespace std;

Ingredients::Ingredients(const string& n, int amo){
	name=n;
	amount=amo;
}

bool sortex(const Ingredients& ing1, const Ingredients& ing2){
	int amo1=ing1.getamount();
	int amo2=ing2.getamount();
	string name1=ing1.getname();
	string name2=ing2.getname();
	if(amo1<amo2){
		return true;
	}
	
	else if(amo1>amo2){
		return false;
	}
	
	else{
		if(name1[0]<name2[0]){
			return true;
		}
		else if(name1[0]==name2[0]){
			if(name1[1]<name2[0]){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}
	}
}