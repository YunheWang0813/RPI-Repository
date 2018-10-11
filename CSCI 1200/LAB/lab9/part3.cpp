#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>
using namespace std;

void add(map<int,string> &phonebook, int number, string const& name) {
  phonebook[number] = name;
}

// given a phone number, determine who is calling
void identify(map<int,string> & phonebook, int number) {
  map<int,string>::iterator it=phonebook.find(number);
  if (it == phonebook.end()) 
    cout << "unknown caller!" << endl;
  else 
    cout << it->second << " is calling!" << endl;
}


int main() {
  // create the phonebook; initially all numbers are unassigned
  map<int,string> phonebook;
  // add several names to the phonebook
  add(phonebook, 1111111, "fred");
  add(phonebook, 2222222, "sally");
  add(phonebook, 3333333, "george");
  add(phonebook, 5555555, "thomas");

  // test the phonebook
  identify(phonebook, 2222222);
  identify(phonebook, 4444444);
  identify(phonebook, 5555555);
}
