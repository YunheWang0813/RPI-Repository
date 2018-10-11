#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(int argc, char* argv[]){
	if (argc!=2) {		//error check
    std::cerr << "Usage: " << argv[0] << " grid-file\n";
    return 1;
  }
	
	ifstream istr(argv[1]);
	if (!istr) {		//error check
    std::cerr << "Couldn't open " << argv[1] << '\n';
    return 1;
  }
	
	map<int,int> counter;
	string info;
	while(istr>>info){
		int temp=atoi(info.c_str());
		map<int,int>::iterator it=counter.find(temp);
		if(it!=counter.end()){
			it->second+=1;
		}
		else{
			counter.insert(pair<int,int>(temp,1));
		}
	}
	
	vector<int> modes;
	int maxval=0;
	map<int,int>::iterator it;
	for(it=counter.begin();it!=counter.end();it++){
		if(it->second > maxval){
			maxval=it->second;
		}
	}
	
	for(it=counter.begin();it!=counter.end();it++){
		if(it->second == maxval){
			cout<<it->first<<" ";
		}
	}
	cout<<endl;
	
	return 0;
}