#include<iostream>
#include<fstream>
using namespace std;

int main(int argc,char *argv[]){
    ifstream ifs(argv[1]);
    string str;
    if(!ifs.good()){
        cerr<<"Can't open"<<argv[1]<<"to read."<<endl;
        return 1;}
    while(getline(ifs,str)){
        cout<<str<<endl;}
    return 0;
}
