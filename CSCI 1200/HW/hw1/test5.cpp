#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

void floodfill(int x,int y,char newc,vector<string> &vec,char inic){
	if(inic==vec[x][y]&&x!=0&&y!=0&&x!=int(vec.size()-1)&&y!=int(vec.size()-1)){
		vec[x][y]=newc;
		floodfill(x+1,y,newc,vec,inic);
		floodfill(x-1,y,newc,vec,inic);
		floodfill(x,y+1,newc,vec,inic);
		floodfill(x,y-1,newc,vec,inic);
	}
}

    
int main(int argc,char *argv[]){
    ifstream ifs(argv[1]);
    string s;
    vector<string> v;
    while (ifs>>s){ 
    v.push_back(s);}
    
	if(string(argv[3])==string("floodfill")){
		char c='X';
		char c2='O';
		
		floodfill(2,10,c2,v,c);
		
            cout<<v[0]<<endl;
		
	}
	
    return 0;
    
}