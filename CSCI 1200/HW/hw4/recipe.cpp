#include<iostream>
#include<list>
#include<string>
#include"recipe.h"
#include"ingredients.h"
using namespace std;

Recipe::Recipe(const string& n){
	name=n;
}

void Recipe::addIngredient(const string& name2, int units){
	Ingredients ingredients(name2,units);
	ingred.push_back(ingredients);
}

void Recipe::sort_k(){
	ingred.sort(alphasort2);
}

bool alphasort(const Recipe& reci1, const Recipe& reci2){
	string name1=reci1.getname();
	string name2=reci2.getname();
	
	if(name1[0]<name2[0]){
		return true;
	}
	else if(name1[0]==name2[0]){
		if(name1[1]<name2[1]){
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

bool alphasort2(const Ingredients& ing1, const Ingredients& ing2){
	string name1=ing1.getname();
	string name2=ing2.getname();
	
	if(name1[0]<name2[0]){
		return true;
	}
	else if(name1[0]==name2[0]){
		if(name1[1]<name2[1]){
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