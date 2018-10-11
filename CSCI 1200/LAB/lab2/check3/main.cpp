#include "Time.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int main(){
	vector<Time> times; //use class to create vector directly
	Time time1(24,0,0);
	times.push_back(time1);
	Time time2(21,2,5);
	times.push_back(time2);
	Time time3(7,2,44);
	times.push_back(time3);
	sort(times.begin(),times.end(),IsEarlierThan);
	for(int i=0;i<int(times.size());i++){
		times[i].print(times[i]);
		cout<<endl;
	}
	return 0;
}