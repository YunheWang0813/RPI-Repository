#ifndef player
#define player

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Player{
	public:
	Player(const string& fst,const string& lst,int wpt,int lpt,int setw);
	
	const string& getfirstname() const {return firstname;}
	const string& getlastname() const {return lastname;}
	int getwonpt() const {return wonpt;}
	int getlostpt() const {return lostpt;}
	int getmatchwon() const {return matchwon;}
	int getmatchlost() const {return matchlost;}
	double getmatchpercent() const {return matchpercent;}
	double getgamepercent() const {return gamepercent;}
	void setfirstname(const string& fst) {firstname=fst;}
	void setlastname(const string& lst) {lastname=lst;}
	void setwonpt(int wpt) {wonpt=wpt;}
	void setlostpt(int lpt) {lostpt=lpt;}
	void setsetwon(int setw) {setwon=setw;}
	void setmatchwon(int matw) {matchwon=matw;}
	void setmatchlost(int matl) {matchlost=matl;}
	void setlongestname(int longest) {longestname=longest;}
	void setmatchpercent(double matper) {matchpercent=matper;}
	void setgamepercent(double gameper) {gamepercent=gameper;}
	void compute_matchpercent();
	void compute_gamepercent();
	void increment(const Player& one_player);
	void pluswonpt(const Player& one_player);
	void pluslostpt(const Player& one_player);
	bool wonorlost() const;
	ostream& output1(ostream& ofs) const;
	ostream& output2(ostream& ofs) const;
	
	private:
	string firstname;
	string lastname;
	int wonpt;
	int lostpt;
	int setwon;
	int matchwon;
	int matchlost;
	int longestname;
	double matchpercent;
	double gamepercent;
};

bool lessmatchper(const Player& player1, const Player& player2);
bool lessgameper(const Player& player1, const Player& player2);
bool alphabetize(const Player& player1, const Player& player2);
#endif