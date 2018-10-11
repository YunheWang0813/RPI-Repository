#include<iostream>
#include<fstream>
#include<vector>
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
               
    if(string(argv[3])==string("dilation")){
        for(int i=0;i<int(v.size());i++){
            for(int j=0;j<int(v[i].length());j++){
                if(i!=int(v.size()-1)){
                    if(v[i+1][j]=='X'&&
                    v[i][j]=='.'){
                        v[i][j]=' ';}
                    }
                    
                if(i!=0){
                    if(v[i-1][j]=='X'&&
                    v[i][j]=='.'){
                        v[i][j]=' ';}
                    }   
            }
        }
        
        for(int i=0;i<int(v.size());i++){
            for(int j=0;j<int(v[i].length());j++){
                if(v[i][j+1]=='X'||
                   v[i][j-1]=='X'){
                        v[i][j]=' ';}
                    }
                }
                
        for(int i=0;i<int(v.size());i++){
            s=repl(v[i],' ',argv[4][0]);
            cout<<s<<endl;}
              
    }
    
    return 0;
    
}
