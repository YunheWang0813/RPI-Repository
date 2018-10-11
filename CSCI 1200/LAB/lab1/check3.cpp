#include <iostream>   // library for reading & writing from the console/keyboard
#include <cmath>      // library with the square root function & absolute value
#include <cstdlib>    // library with the exit function
using namespace std;

int main(){
    cout<<"Enter an integer"<<endl;
    int x;
    cin>>x;
    int i;
    float num[x],total,ave;
    total=0;
    cout<<"Enter values"<<endl;
    for(i=0;i<x;i++){
        float a;
        cin>>a;
        num[i]=a;
        total+=a;}
    ave=total/x;
    cout<<"The average is "<<ave<<endl;
    int b;
    float last[100];
    b=0;
    for(i=0;i<x;i++){
        if(num[i]<ave){
            last[b]=num[i];
            b+=1;}
    }
    for(i=0;i<b;i++){
        cout<<last[i]<<endl;}
}
