#ifndef _ingredients
#define _ingredients

#include<iostream>
#include<string>
#include<list>
using namespace std;

class Ingredients{
	public:
	Ingredients(const string& n, int amo);
	
	const string& getname() const {return name;}
	int getamount() const {return amount;}
	
	void setname(const string& n) {name=n;}
	void setamount(int amo) {amount=amo;}
	void increment(int units){amount+=units;}
	void decrement(int units) {amount-=units;}
	
	private:
	string name;
	int amount; 	
};

	bool sortex(const Ingredients& ing1, const Ingredients& ing2);

#endif