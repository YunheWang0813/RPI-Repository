#include<iostream>
#include<vector>
#include<string>
#include"ship.h"
using namespace std;

Ship::Ship(const string& n){
	name=n;
	if(n=="submarine"){
		size=1;
	}
	else if(n=="destroyer"){
		size=2;
	}
	else if(n=="cruiser"){
		size=3;
	}
	else if(n=="battleship"){
		size=4;
	}
	else if(n=="carrier"){
		size=5;
	}
	else if(n=="cargo"){
		size=6;
	}
	else if(n=="tanker"){
		size=7;
	}
}