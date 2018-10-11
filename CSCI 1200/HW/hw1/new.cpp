#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main(){
    ifstream ifs("input4.txt"); 
    vector<string> v; 
    string str;
    while (ifs>>str){ 
        v.push_back(str);}
    cout<<v[4][1]<<endl;
    return 0;
} 
