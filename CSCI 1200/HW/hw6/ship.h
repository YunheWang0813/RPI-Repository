#ifndef ship_
#define ship_

#include<iostream>
#include<string>
using namespace std;

class Ship{
public:
  Ship(const string& n);
  const string& getname() const {return name;}
  int getsize() const {return size;}
  
private:
  int size;
  string name;
};

#endif