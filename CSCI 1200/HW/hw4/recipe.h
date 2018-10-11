#ifndef _recipe
#define _recipe

#include<iostream>
#include<string>
#include<list>
#include"ingredients.h"
using namespace std;

class Recipe{
	public:
	Recipe(const string& n);

	const string& getname() const {return name;}
	void setname(const string& n) {name=n;}
	list<Ingredients> getlist() const {return ingred;} //to get the list of recipe in the main function

	void addIngredient(const string& name2, int units);
	void sort_k();
	
	private:
	string name;
	list<Ingredients> ingred;
	
};

bool alphasort(const Recipe& reci1, const Recipe& reci2);
bool alphasort2(const Ingredients& ing1, const Ingredients& ing2); //the similar sort functions to sort perticular list

#endif