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
    
    

    if(string(argv[3])==string("replace")){
        while(getline(ifs,s)){
            s=repl(s,'X','O');
            cout<<s<<endl;}
        }
            

    return 0;
}
