// CSCI 1200 Data Structures
// Homework 5: Multi-Linked Lists


// NOTE: You should not need to make any changes to this file, except
// to add your own test cases at the bottom of the file where
// indicated.


#include <iostream>
#include <cmath>
#include <string>
#include <list>
#include <vector>
#include <cassert>
#include <cstdlib>

#include "multi_linked_list.h"

void ProvidedTests();
void StudentTests();


// ================================================================================
// A simple function to test if two STL lists contain the "same" elements
// returns true if it contains the same number of elements in the same order
// otherwise returns false
template <class T> bool same(const std::list<T> &a, const std::list<T> &b) {
  if (a.size() != b.size()) return false;
  typename std::list<T>::const_iterator a_itr = a.begin();
  typename std::list<T>::const_iterator b_itr = b.begin();
  while (a_itr != a.end()) {
    if (*a_itr != *b_itr) return false;
    a_itr++;
    b_itr++;
  }
  return true;
}



// ================================================================================
// This program stress tests the templated MultiLL container class


int main() {
  ProvidedTests();
  StudentTests();
}


// ================================================================================
// ================================================================================

void ProvidedTests() {

  std::cout << "Begin ProvidedTests..." << std::endl;

  // The test data (stored in STL lists)
  std::list<std::string> songs;
  songs.push_back("hound dog");
  songs.push_back("poker face");
  songs.push_back("brown eyed girl");
  songs.push_back("let it be");
  songs.push_back("walk like an egyptian");
  songs.push_back("man in the mirror");
  songs.push_back("stairway to heaven");
  songs.push_back("dancing in the street");
  songs.push_back("every breath you take");
  songs.push_back("hotel california");
  // the same data, sorted!
  std::list<std::string> sorted_songs(songs);
  sorted_songs.sort();


  // create an empty multi-linked list and fill it with the test data
  MultiLL<std::string> my_list;
  for (std::list<std::string>::iterator itr = songs.begin(); itr != songs.end(); itr++) {
    my_list.add(*itr);
  }
  assert (songs.size() == my_list.size());



  // -------------------
  // iterator tests

  // test the chronological iterator (forwards)
  std::cout << "chronological order" << std::endl;
  std::list<std::string> chrono_order;
  MultiLL<std::string>::iterator itr = my_list.begin_chronological();
  while (itr != my_list.end_chronological()) {
    std::cout << "  " << *itr << std::endl;
    chrono_order.push_back(*itr);
    itr++;
  }
  std::cout << std::endl;
  assert (same(songs,chrono_order));


  // test the sorted order iterator (forwards)
  std::cout << "sorted order" << std::endl;
  std::list<std::string> sorted_order;
  itr = my_list.begin_sorted();
  while (itr != my_list.end_sorted()) {
    std::cout << "  " << *itr << std::endl;
    sorted_order.push_back(*itr);
    itr++;
  }
  std::cout << std::endl;
  assert (same(sorted_songs,sorted_order));


  // test the random order iterator
  std::cout << "random order" << std::endl;
  std::list<std::string> random_order;
  itr = my_list.begin_random();
  for (unsigned int i = 0; i < my_list.size(); i++,itr++) {
    std::cout << "  " << *itr << std::endl;
    random_order.push_back(*itr);
  }
  std::cout << std::endl;
  // loop through the elements a second time (the order should be the same!)
  std::list<std::string>::iterator itr2 = random_order.begin();
  for (unsigned int i = 0; i < my_list.size(); i++,itr++,itr2++) {
    // verify that the elements repeat the order
    assert (*itr == *itr2);
  }
  std::list<std::string> random_order_check(random_order);
  random_order_check.sort();
  // verify that all of the elements appeared in the initial loop
  assert (same(sorted_songs,random_order_check));



  // test the re-randomization by creating a new random iterator
  std::cout << "random order 2" << std::endl;
  std::list<std::string> random_order2;
  itr = my_list.begin_random();
  for (unsigned int i = 0; i < my_list.size(); i++,itr++) {
    std::cout << "  " << *itr << std::endl;
    random_order2.push_back(*itr);
  }
  std::cout << std::endl;
  // with over 3 million different possible permutations of 10
  // elements, it is highly unlikely they will be the same!
  assert (!same(random_order,random_order2));


  
  // -------------------
  // erase tests

  // erase the first element inserted
  itr = my_list.begin_chronological();
  assert (*itr == "hound dog");
  itr = my_list.erase(itr);
  assert (*itr == "poker face");
  assert (my_list.size() == 9);
  std::cout << "erased: hound dog" << std::endl;

  // erase the second to last element in sorted order
  itr = my_list.begin_sorted();
  for (int i = 0; i < 7; i++) { itr++; }
  assert (*itr == "stairway to heaven");
  itr = my_list.erase(itr);
  assert (*itr == "walk like an egyptian");
  assert (my_list.size() == 8);  
  std::cout << "erased: stairway to heaven" << std::endl;

  // erase the third element in the random order
  itr = my_list.begin_random();
  itr++;
  itr++;
  std::string tmp = *itr;
  // note that the return value of erase with a random iterator is undefined
  my_list.erase(itr);
  std::cout << "erased: " << tmp << std::endl;
  assert (my_list.size() == 7);
  assert (!my_list.empty());

  my_list.clear();
  assert (my_list.empty());
  assert (my_list.size() == 0);
  std::cout << "cleared the whole list!" << std::endl << std::endl;
  std::cout << "Finished ProvidedTests." << std::endl;
}

// ================================================================================
// ================================================================================

void StudentTests() {

  std::cout << "Begin StudentTests..." << std::endl;

  // ---------------------------
  // ADD YOUR OWN TEST CASES BELOW
  
  // be sure to test:
  //   copy constructor
  //   assignment operator
  //   destructor
  std::list<std::string> songs;
  songs.push_back("hound dog");
  songs.push_back("poker face");
  songs.push_back("brown eyed girl");
  songs.push_back("let it be");
  songs.push_back("walk like an egyptian");
  songs.push_back("man in the mirror");
  songs.push_back("stairway to heaven");
  songs.push_back("dancing in the street");
  songs.push_back("every breath you take");
  songs.push_back("hotel california");

  MultiLL<std::string> my_list;
  for (std::list<std::string>::iterator itr = songs.begin(); itr != songs.end(); itr++) {
    my_list.add(*itr);
  }
  
  MultiLL<std::string> my_list_copy;
  my_list_copy=my_list;
  
  std::cout << "chronological order original" << std::endl;
  MultiLL<std::string>::iterator itr = my_list.begin_chronological();
  while (itr != my_list.end_chronological()) {
    std::cout << "  " << *itr << std::endl;
    itr++;
  }
  std::cout << std::endl;
  
  std::cout << "chronological order copy" << std::endl;
  MultiLL<std::string>::iterator itr2= my_list_copy.begin_chronological();
  while (itr2 != my_list_copy.end_chronological()) {
    std::cout << "  " << *itr2 << std::endl;
    itr2++;
  }
  std::cout << std::endl;
  
  std::cout << "sorted order original" << std::endl;
  MultiLL<std::string>::iterator itr5 = my_list.begin_sorted();
  while (itr5 != my_list.end_sorted()) {
    std::cout << "  " << *itr5 << std::endl;
    itr5++;
  }
  std::cout << std::endl;
  
  std::cout << "sorted order copy" << std::endl;
  MultiLL<std::string>::iterator itr6= my_list_copy.begin_sorted();
  while (itr6 != my_list_copy.end_sorted()) {
    std::cout << "  " << *itr6 << std::endl;
    itr6++;
  }
  std::cout << std::endl;
  
  std::cout << "random order original" << std::endl;
  itr = my_list.begin_random();
  for (unsigned int i = 0; i < my_list.size(); i++,itr++) {
    std::cout << "  " << *itr << std::endl;
  }
  std::cout << std::endl;
  
  std::cout << "random order copy" << std::endl;
  itr = my_list.begin_random();
  for (unsigned int i = 0; i < my_list_copy.size(); i++,itr++) {
    std::cout << "  " << *itr << std::endl;
  }
  std::cout << std::endl;
  
  //   all corner cases of erase
  
  //   decrement operator for the chronological & sorted iterators
  
  //   pre vs. post increment & decrement operations for iterators
  
  //   MultiLL containing types other than std::string
  std::list<int> numbers;
  numbers.push_back(2);
  numbers.push_back(1);
  numbers.push_back(15);
  numbers.push_back(87);
  numbers.push_back(8);
  numbers.push_back(4);
  numbers.push_back(99);
  numbers.push_back(13);
  numbers.push_back(7);
  numbers.push_back(5);

  MultiLL<int> my_list_numbers;
  for (std::list<int>::iterator itr3 = numbers.begin(); itr3 != numbers.end(); itr3++) {
    my_list_numbers.add(*itr3);
  }
  
  std::cout << "check type" << std::endl;
  MultiLL<int>::iterator itr4= my_list_numbers.begin_chronological();
  while (itr4 != my_list_numbers.end_chronological()) {
    std::cout << "  " << *itr4 << std::endl;
    itr4++;
  }
  std::cout << std::endl;
  
  //   anything else that is necessary


  std::cout << "Finished StudentTests." << std::endl;
}

// ================================================================================
