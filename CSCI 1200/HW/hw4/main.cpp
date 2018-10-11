//
// PROVIDED CODE FOR HOMEWORK 4: GROCERY LISTS
// 
// You may use none, a little, or all of this, as you choose, but we
// strongly urge you to examine it carefully.  You may modify this
// code as you wish to complete the assignment.
//


#include <cassert>
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "recipe.h"
#include "kitchen.h"
#include "ingredients.h"


// Helper functions
void readRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes);
void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen);
void printRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes);
void makeRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes, Kitchen &kitchen);
void recipeSuggestions(std::ostream &ostr, std::list<Recipe> &recipes, const Kitchen &kitchen);

// The main loop parses opens the files for I/O & parses the input
int main(int argc, char* argv[]) {

  // Check the number of arguments.
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " in-file out-file\n";
    return 1;
  }
  // Open and test the input file.
  std::ifstream istr(argv[1]);
  if (!istr) {
    std::cerr << "Could not open " << argv[1] << " to read\n";
    return 1;
  }
  // Open and test the output file.
  std::ofstream ostr(argv[2]);
  if (!ostr) {
    std::cerr << "Could not open " << argv[2] << " to write\n";
    return 1;
  }

  // the kitchen & recipe list
  Kitchen kitchen;
  std::list<Recipe> recipes;

  // some variables to help with parsing
  char c;
  while (istr >> c) {
    if (c == 'r') {
      // READ A NEW RECIPE
      readRecipe(istr,ostr,recipes);

    } else if (c == 'a') {
      // ADD INGREDIENTS TO THE KITCHEN
      addIngredients(istr,ostr,kitchen);
      
    } else if (c == 'p') {
      // PRINT A PARTICULAR RECIPE
      printRecipe(istr,ostr,recipes);

    } else if (c == 'm') {
      // MAKE SOME FOOD
      makeRecipe(istr,ostr,recipes,kitchen);

    } else if (c == 'k') {
      // PRINT THE CONTENTS OF THE KITCHEN
      kitchen.printIngredients(ostr);

    } else if (c == 's') {
      // SUGGEST ALL RECIPES THAT CAN BE MADE INDIVIDUALLY FROM THE
      //   CURRENT CONTENTS OF THE KITCHEN
      recipeSuggestions(ostr,recipes,kitchen);

    } else if (c == 'd') {
      // EXTRA CREDIT: SUGGEST THE COLLECTION OF RECIPES THAT CAN BE
      // MADE TOGETHER THAT USE THE MAXIMUM NUMBER OF UNITS OF
      // INGREDIENTS
    } else {
      std::cerr << "unknown character: " << c << std::endl;
      exit(0);
    }
  }  
}


void readRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes) {
  int units;
  std::string name, name2;  
  istr >> name;
  // build the new recipe
  Recipe r(name);
  
  list<Recipe>::iterator i=recipes.begin();
  bool judge=true;
  
  while(i!=recipes.end()){
	  if((*i).getname()==name){
		  judge=false; //judge if the recipe already exists
		  break;
	  }
	  i++; //avoid infinity loop
  }  
  
  while (1) {
    istr >> units;
    if (units == 0) break;
    assert (units > 0);
    istr >> name2;
    r.addIngredient(name2,units);
  }
  // add it to the list
  
  
  if(judge){
	  ostr << "Recipe for " << name << " added" << std::endl;
	  recipes.push_back(r);
  }
  
  else{
	  ostr << "Recipe for " << name << " already exists" << std::endl;
  }
  
}


void addIngredients(std::istream &istr, std::ostream &ostr, Kitchen &kitchen) {
  int units;
  std::string name;
  int count = 0;
  while (1) {
    istr >> units;
    if (units == 0) break;
    assert (units > 0);
    istr >> name;
    // add the ingredients to the kitchen
    kitchen.addIngredient(name,units);
    count++;
  }
  if(count==1){
	  ostr << "1 ingredient added to kitchen" << std::endl;
  }
  else{
	  ostr << count << " ingredients added to kitchen" << std::endl;
  }
}


void printRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes) {
  std::string name;
  istr >> name;
  Recipe r(name);
 
  list<Recipe>::iterator i=recipes.begin();
  bool judge=true;
  
  while(i!=recipes.end()){
	  if((*i).getname()==name){
		  judge=false;
		  ostr<<"To make "<<name<<", mix together:"<<std::endl;
		  (*i).sort_k();
		  list<Ingredients> temp=(*i).getlist(); //to make the required list get fixed
		  list<Ingredients>::iterator x=temp.begin();
		  while(x!=temp.end()){
			if((*x).getamount()==1){
				ostr<<"  "<<(*x).getamount()<<" unit of "<<(*x).getname()<<std::endl;
			}
			else{
				ostr<<"  "<<(*x).getamount()<<" units of "<<(*x).getname()<<std::endl;
			}
			x++;
		  }
		  break; //avoid the unnecessary loop
	  }
	  i++;
  } 

  if(judge){
	  ostr<<"No recipe for "<<name<<std::endl;
  }
}


void makeRecipe(std::istream &istr, std::ostream &ostr, std::list<Recipe> &recipes, Kitchen &kitchen) {
  std::string name;
  istr >> name;
  bool judge1=false;  //to check if there is a recipe for the food
  bool judge2=false;  //to check if the food can be made
  list<Recipe>::iterator i=recipes.begin();
  list<Ingredients> need;  //store the information of ingredients that need to buy to make food
  while(i!=recipes.end()){  
	  if((*i).getname()==name){
		  judge1=true;
		  list<Ingredients> kit=kitchen.getlist();
		  list<Ingredients>::iterator x=kit.begin();
		  list<Ingredients> reci=(*i).getlist();
		  list<Ingredients>::iterator y=reci.begin();
		  int count=0; //to check if there are required ingredients
		  
		  while(y!=reci.end()){	  
			  x=kit.begin(); //make iterator always point to the first of the list
			  bool judge3=false;  //to check if there is the name of required ingredients in the kitchen
			  while(x!=kit.end()){
				  if((*y).getname()==(*x).getname()){
					  judge3=true;
					  if((*x).getamount()>=(*y).getamount()){
						  count+=1;
					  }
					  else{  //to check if there is enough ingredients to make food in kitchen
						  int delta=(*y).getamount()-(*x).getamount(); //to compute how many ingredients are lacking
						  Ingredients needing((*x).getname(),delta);
						  need.push_back(needing);
					  }
				  }
				  x++;
			  }
			  if(!judge3){ //just append the information of original recipe
					  Ingredients needing((*y).getname(),(*y).getamount());
					  need.push_back(needing);
				  }
			  y++;
		  }

		  if(count==reci.size()){  //decrese the amount of ingredients that are used to make the food from the kitchen
			  judge2=true;
			  y=reci.begin();
			  while(y!=reci.end()){
				  x=kit.begin();
				  while(x!=kit.end()){
					  if((*y).getname()==(*x).getname()){
						  kitchen.decreaseIngredient((*x).getname(), (*y).getamount());
					  }
					  x++;
				  }
				  y++;
			  }
		  }
		  break;
	  }
	  i++;
  }
  
  if(!judge1){
	  ostr<<"Don't know how to make "<<name<<std::endl;
	  return; //end the function when there is no required recipe
  }

  if(judge2){
	  ostr<<"Made "<<name<<std::endl;
  }
	  
  else if(!judge2){
	  ostr<<"Cannot make "<<name<<", need to buy:"<<std::endl;
	  need.sort(alphasort2);
	  list<Ingredients>::iterator n=need.begin();
	  while(n!=need.end()){
		  if((*n).getamount()==1){
				ostr<<"  "<<(*n).getamount()<<" unit of "<<(*n).getname()<<std::endl;
			}
			else{
				ostr<<"  "<<(*n).getamount()<<" units of "<<(*n).getname()<<std::endl;
			}
			n++;
	  }
  }
	  
}


void recipeSuggestions(std::ostream &ostr, std::list<Recipe> &recipes, const Kitchen &kitchen) {
	list<Recipe>::iterator i=recipes.begin();
	list<Recipe> canbemade; //store the name of recipe that can be prepared
	list<Ingredients> kit=kitchen.getlist();
	list<Ingredients>::iterator x=kit.begin();
	list<Ingredients> reci=(*i).getlist();
	list<Ingredients>::iterator y=reci.begin();
	while(i!=recipes.end()){
		int count=0;
		reci=(*i).getlist();  //always acquire the correspond ingredients list of the specific recipe
		y=reci.begin();
		
		while(y!=reci.end()){
			x=kit.begin();
			while(x!=kit.end()){
				if((*y).getname()==(*x).getname()){
					if((*y).getamount()<=(*x).getamount()){

						count+=1;
					}
				}
				x++;
			}
			y++;
		}

		if(count==reci.size()){
			Recipe sucreci((*i).getname());
			canbemade.push_back(sucreci);
		}
		
		i++;
	}
	
	if(canbemade.size()>1){
		canbemade.sort(alphasort);
		ostr<<"Recipes that can be prepared:"<<std::endl;
		list<Recipe>::iterator f=canbemade.begin();
		while(f!=canbemade.end()){
			ostr<<"  "<<(*f).getname()<<std::endl;
			
			f++;
		}
	}
	
	else if(canbemade.size()==1){
		ostr<<"Recipe that can be prepared:"<<std::endl;
		list<Recipe>::iterator f=canbemade.begin();
		ostr<<"  "<<(*f).getname()<<std::endl;
	}
	
	else{
		ostr<<"No recipes can be prepared"<<std::endl;
	}
}
