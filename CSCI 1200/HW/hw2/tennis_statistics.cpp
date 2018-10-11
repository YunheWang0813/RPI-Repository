#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<iomanip>
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
		
		while(formerwon!=3&&latterwon!=3){ //continue until one of two players win 3 sets
			ifs>>score;
			parse_set(score,former,latter); //change score string to 2 number by parse_set function
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
		}
			
		
		Player player1(first1,last1,formerpt,latterpt,formerwon);
		bool judge1=true; //to check if player1 is already in vector Player
		for(int i=0;i<int(players.size());i++){ //if there is, update his/her information
			if(player1.getfirstname()==players[i].getfirstname()&&
			   player1.getlastname()==players[i].getlastname()){
				players[i].pluswonpt(player1);
				players[i].pluslostpt(player1);
				players[i].increment(player1);
				judge1=false;
				break;
			}
		}
		if(judge1){ //if there isn't, add him/her to the vector Player
			players.push_back(player1);
			}
		
		Player player2(first2,last2,latterpt,formerpt,latterwon); //the same thing apply to player2
		bool judge2=true;
		for(int i=0;i<int(players.size());i++){
			if(player2.getfirstname()==players[i].getfirstname()&&
			   player2.getlastname()==players[i].getlastname()){
				players[i].pluswonpt(player2);
				players[i].pluslostpt(player2);
				players[i].increment(player2);
				judge2=false;
				break;
			}
		}
		if(judge2){
			players.push_back(player2);
		    }
		
	}
	
	ifs.close();
	
	ofstream ofs(argv[2]);
	
	int longestname=0;
	for(int i=0;i<int(players.size());i++){
		players[i].compute_matchpercent();
		players[i].compute_gamepercent();
		int a=int(players[i].getfirstname().length())+int(players[i].getlastname().length())+1;
		if(a>longestname){
			longestname=a;
		}
	}
	
	ofs<<"MATCH STATISTICS"<<endl;
	ofs<<"Player"<<setw(longestname+17)<<"W    L   percentage"<<endl;

	sort(players.begin(),players.end(),alphabetize); //alphabetize the vector
	sort(players.begin(),players.end(),lessmatchper);
	
	for(int i=0;i<int(players.size());i++){
		players[i].setlongestname(longestname);
		players[i].output1(ofs);
	}
	ofs<<endl;
	
	ofs<<"GAME STATISTICS"<<endl;
	ofs<<"Player"<<setw(longestname+17)<<"W    L   percentage"<<endl;
	
	sort(players.begin(),players.end(),lessgameper);
	
	for(int i=0;i<int(players.size());i++){
		players[i].output2(ofs);
	}
	
	ofs.close();
	
	return 0;
}