#include<iostream>
#include<fstream>
#include<vector>
#include<iomanip>
using namespace std;

void parse_set(std::string &set, int &games_won, int &games_lost) {
int i = set.find('-');
games_won = atoi(set.substr(0,i).c_str());
games_lost = atoi(set.substr(i+1,set.size()-i-1).c_str());
}

int main(int argc, char* argv[]){
	ifstream ifs(argv[1]);
	if(!ifs){
		cerr<<"Could not open "<<argv[1]<<" to read"<<endl;
		return 1
	}
	
	vector<
	ifs>>name>>score
}