#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
#include"player.h"
using namespace std;

Player::Player(const string& fst,const string& lst,int wpt,int lpt,int setw){
	firstname=fst;
	lastname=lst;
	wonpt=wpt;
	lostpt=lpt;
	setwon=setw;
	if(setwon==3){
		matchwon=1;
		matchlost=0;
	}
	else{
		matchwon=0;
		matchlost=1;
	}
}

bool Player::wonorlost() const{
	return setwon==3;
}

void Player::compute_matchpercent(){
	matchpercent=double(matchwon)/(matchwon+matchlost);
}

void Player::compute_gamepercent(){
	gamepercent=double(wonpt)/(wonpt+lostpt);
}

void Player::increment(const Player& one_player){
	if(one_player.wonorlost()){
		matchwon+=1;
	}
	else{
		matchlost+=1;
	}
}

void Player::pluswonpt(const Player& one_player){
	wonpt+=one_player.getwonpt();
}

void Player::pluslostpt(const Player& one_player){
	lostpt+=one_player.getlostpt();
}

ostream& Player::output1(ostream& ofs) const{
	ofs<<firstname<<' '<<lastname<<setw(longestname-firstname.length()-lastname.length()+4)
	<<matchwon<<setw(5)<<matchlost<<setw(13)<<setprecision(3)<<fixed<<matchpercent<<endl;
	return ofs;
}

ostream& Player::output2(ostream& ofs) const{
	ofs<<firstname<<' '<<lastname<<setw(longestname-firstname.length()-lastname.length()+4)
	<<wonpt<<setw(5)<<lostpt<<setw(13)<<setprecision(3)<<fixed<<gamepercent<<endl;
	return ofs;
}

bool lessmatchper(const Player& player1, const Player& player2){
	if(player1.getmatchpercent()>player2.getmatchpercent()){
		return true;
	}
	else
		return false;
}

bool lessgameper(const Player& player1, const Player& player2){
	if(player1.getgamepercent()>player2.getgamepercent()){
		return true;
	}
	else
		return false;
}

bool alphabetize(const Player& player1, const Player& player2){
	char a1=player1.getlastname()[0];
	char b1=player2.getlastname()[0];
	char a2=player1.getfirstname()[0];
	char b2=player2.getfirstname()[0];
	if(a1<b1){
		return true;
	}
	else if(a1==b1&&a2<b2){
		return true;
	}
	else{
		return false;
	}
}

