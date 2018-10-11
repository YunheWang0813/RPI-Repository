#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

string repl(string str,char ch1,char ch2){
  for(int i=0;i<str.length();i++){
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
    
    if(!ifs.good()){
        cerr<<"Can't open"<<argv[1]<<"to read."<<endl;
        return 1;}
    
    if(string(argv[3])==string("replace"){
        while(getline(ifs,s)){
            s=repl(s,'X','O');
            cout<<s<<endl;}
            
    if(string(argv[3])==string("dilation"){
        for(i=0;i<ifs;i++){
            for(j=0;j<v[i];j++){
                if(v[i][j+1]=='X'){
                    v[i][j]=argv[4];}
                if(v[i][j-1]=='X'){
                    v[i][j]=argv[4];}
                if(v[i+1][j]=='X'){
                    v[i][j]="X";}
                }
        
    return 0;
}
