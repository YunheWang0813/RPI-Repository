#include<iostream>
#include<fstream>
#include<vector>
#include <cstdlib>
using namespace std;

string repl(string str,char ch1,char ch2){
  for(int i=0;i<int(str.length());i++){
    if(str[i]==ch1){
      str[i]=ch2;}
    }
  return str;
}

    
int main(int argc,char *argv[]){
    ifstream ifs(argv[1]);
    string s;
    vector<string> v;
    while (ifs>>s){ 
    v.push_back(s);}
    
	if(string(argv[3])==string("floodfill")){
		vector<int> v1;
		vector<int> v2;
		const char inic=v[atoi(argv[4])][atoi(argv[5])];
		int x=atoi(argv[4]);
		int y=atoi(argv[5]);
		v1.push_back(x);
		v2.push_back(y);
		
		for(int i=0;i<int(v1.size());i++){
				v[v1[i]][v2[i]]=' ';
				
				if(v[v1[i]+1][v2[i]]==inic){
					v1.push_back(v1[i]+1);
					v2.push_back(v2[i]);
				}
				
				if(v[v1[i]-1][v2[i]]==inic){
					v1.push_back(v1[i]-1);
					v2.push_back(v2[i]);
				}
				
				if(v[v1[i]][v2[i]+1]==inic){
					v1.push_back(v1[i]);
					v2.push_back(v2[i]+1);
				}
				
				if(v[v1[i]][v2[i]-1]==inic){
					v1.push_back(v1[i]);
					v2.push_back(v2[i]-1);
				}
			}
			
        for(int i=0;i<int(v.size());i++){
            s=repl(v[i],' ',argv[6][0]);
            cout<<s<<endl;}
			
	}
	
    return 0;
    
}
