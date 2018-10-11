#include<iostream>
#include<list>
#include"kitchen.h"
#include"ingredients.h"
using namespace std;



void Kitchen::addIngredient(const string& name2, int units){
	Ingredients ingredients(name2,units);
	
	list<Ingredients>::iterator i=ingred.begin();
	bool judge=true;
  
	while(i!=ingred.end()){
		if((*i).getname()==name2){
			judge=false;
			(*i).increment(units);
			break;
		}
		i++;
	}
	
	if(judge){
		ingred.push_back(ingredients);
	}
	
}

void Kitchen::decreaseIngredient(const string& name2, int units){
	list<Ingredients>::iterator i=ingred.begin();
  
	while(i!=ingred.end()){
		if((*i).getname()==name2){
			(*i).decrement(units);
			break;
		}
		i++;
	}
	
}

ostream& Kitchen::printIngredients(ostream& ostr) {
	ostr<<"In the kitchen:"<<endl;
	ingred.sort(sortex);
	list<Ingredients>::iterator i=ingred.begin();
	while(i!=ingred.end()){
		if((*i).getamount()==0){
				i=ingred.erase(i);  //to verify if the ingredient is used up and need to be removed from the list
				continue;
			}
		else if((*i).getamount()==1){
				ostr<<"  "<<(*i).getamount()<<" unit of "<<(*i).getname()<<std::endl;
			}
		else{
				ostr<<"  "<<(*i).getamount()<<" units of "<<(*i).getname()<<std::endl;
			}
		i++;
	}
}