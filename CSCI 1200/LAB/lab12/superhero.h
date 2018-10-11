#ifndef _superhero_
#define _superhero_

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Superhero{
public:
	Superhero(const string& n, const string& id, const string& p){
		name=n;
		identity=id;
		power=p;
		condition=0;
	}
	const string& getName() const {return name;}
	const string& getPower() const {return power;}
	bool operator== (const string& id) const {
		return identity==id;
	}
	bool operator!= (const string& id) const {
		return identity!=id;
	}
	bool isGood() const {
		return condition%2==0;
	}
	void operator- () {
		condition+=1;
	}
	bool operator== (const Superhero& s1) const {
		string temps=s1.getName();
		return name==temps;
	}
	
	const string& getTrueIdentity() const {return identity;}
	
private:
	string name;
	string identity;
	string power;
	int condition;
};

ostream& operator<< (ostream& ostr, Superhero const& s);
bool operator> (const Superhero& s1, const Superhero& s2);

#endif