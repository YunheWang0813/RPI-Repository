#ifndef _kitchen
#define _kitchen

#include<iostream>
#include<string>
#include<list>
#include"ingredients.h"
using namespace std;

class Kitchen{
	public:
	
	
	list<Ingredients> getlist() const {return ingred;}
	void addIngredient(const string& name2, int units);
	void decreaseIngredient(const string& name2, int units);
	ostream& printIngredients(ostream& ostr);
	
	
	private:
	list<Ingredients> ingred;
	
	
	
};


#endif