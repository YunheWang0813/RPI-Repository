#include<iostream>
#include<vector>
#include<list>
using namespace std;


int main(){

list<int> a;
unsigned int i;
for ( i=1; i<10; ++i ) a.push_back( i*i );
list<int>::reverse_iterator ri;
for( ri = a.rbegin(); ri != a.rend(); ++ri )
cout << *ri << endl;

return 0;
}