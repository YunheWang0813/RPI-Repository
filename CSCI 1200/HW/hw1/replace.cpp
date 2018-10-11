#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(int argc,char *argv[]){
    ifstream ifs(argv[1]);
    string s;
    if(!ifs.good()){
        cerr<<"Can't open"<<argv[1]<<"to read."<<endl;
        return 1;}
    while(getline(ifs,s)){
        s.replace(s.begin(),s.end(),'X','Y');
        cout<<s<<endl;}
    return 0;
}
