#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<algorithm>  //to use sort()
#include<string>
#include"player.h"
using namespace std;

void parse_set(std::string &set, int &games_won, int &games_lost) {
int i = set.find('-');
games_won = atoi(set.substr(0,i).c_str());
games_lost = atoi(set.substr(i+1,set.size()-i-1).c_str());
}

int main(int argc, char* argv[]){
	ifstream ifs(argv[1]); //introduce the text file
	if(!ifs){
		cerr<<"Could not open "<<argv[1]<<" to read"<<endl;
		return 1; //error check
	}
	
	string first1;
	string last1;
	string d;
	string first2;
	string last2;
	string score;
	vector<Player> players;
	
	while(ifs>>first1>>last1>>d>>first2>>last2){ //every time read the first 5 strings of the line
		
			int former=0; //initialize the data for looping every time
			int latter=0;
			int formerwon=0;
			int latterwon=0;
			int formerpt=0;
			int latterpt=0;
			bool check=true;
			cout<<first1<<" "<<last1<<" "<<d<<" "<<first2<<" "<<last2<<"  ";
		
		while(formerwon!=3&&latterwon!=3){ //continue until one of two players win 3 sets
			ifs>>score;
			parse_set(score,former,latter); //change score string to 2 number by parse_set function
			cout<<former<<" "<<latter<<" "<<endl;
			if(former>latter){
				formerwon+=1;
				formerpt+=former;
				latterpt+=latter;
			}
			else{
				latterwon+=1;
				latterpt+=latter;
				formerpt+=former;
			}
			cout<<score<<" "<<formerpt<<" "<<latterpt<<" ";
		}
	}
	return 0;
}