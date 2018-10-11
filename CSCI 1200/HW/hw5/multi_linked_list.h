#ifndef multilist_h_
#define multilist_h_

#include <iostream>
#include <cassert>
#include "mtrand.h"
using namespace std;

// -----------------------------------------------------------------
// NODE CLASS

template <class T>
class Node {
public:
  Node() : chrono_next(NULL), chrono_prev(NULL), sorted_next(NULL), sorted_prev(NULL), random_next(NULL) {}
  Node(const T& v) : value_(v), chrono_next(NULL), chrono_prev(NULL), sorted_next(NULL), sorted_prev(NULL), random_next(NULL){}

  T value_;
  Node<T>* chrono_next;  //define all of the node
  Node<T>* chrono_prev;
  Node<T>* sorted_next;
  Node<T>* sorted_prev;
  Node<T>* random_next;
};

template <class T> class MultiLL;

// -----------------------------------------------------------------
// LIST ITERATOR

template <class T>
class list_iterator {
public:
  list_iterator() : ptr_(NULL), flag(0) {}
  list_iterator(Node<T>* p, int f) : ptr_(p), flag(f) {}
  list_iterator<T>& operator=(const list_iterator<T>& old) {
    ptr_ = old.ptr_; flag=old.flag; return *this; }
  ~list_iterator() {}

  T& operator*()  { return ptr_->value_;  }

  list_iterator<T>& operator++() { //pre-increment
	if(flag==1){
		ptr_ = ptr_->chrono_next;
		return *this;
	}

	else if(flag==2){
		ptr_ = ptr_->sorted_next;
		return *this;
	}
	
	else if(flag==3){
		ptr_ = ptr_->random_next;
		return *this;
	}
  }
  
  list_iterator<T> operator++(int) { //post-increment
   list_iterator<T> temp(*this);
   if(flag==1){
		ptr_ = ptr_->chrono_next;
   }
   
   else if(flag==2){
	    ptr_ = ptr_->sorted_next;
   }
   
   else if(flag==3){
	    ptr_ = ptr_->random_next;
   }
   return temp;
  }
  
  list_iterator<T>& operator--() { //pre-decrement
    if(flag==1){
		ptr_ = ptr_->chrono_prev;
		return *this;
	}

	else if(flag==2){
		ptr_ = ptr_->sorted_prev;
		return *this;
	}

  }
  
  list_iterator<T> operator--(int) { //post-decrement
   list_iterator<T> temp(*this);
   if(flag==1){
		ptr_ = ptr_->chrono_prev;
   }
   
   else if(flag==2){
	    ptr_ = ptr_->sorted_prev;
   }
   return temp;
  }

  friend class MultiLL<T>;

  bool operator==(const list_iterator<T>& r) const {
    return ptr_ == r.ptr_; }
  bool operator!=(const list_iterator<T>& r) const {
    return ptr_ != r.ptr_; }

private:
  Node<T>* ptr_; 
  int flag;  //to determine what type of iterator should be used
};

// -----------------------------------------------------------------
// LIST CLASS DECLARATION

template <class T>
class MultiLL {
public:
  // default constructor, copy constructor, assignment operator, & destructor
  MultiLL() : chrono_head(NULL), chrono_tail(NULL), sorted_head(NULL), sorted_tail(NULL), random_head(NULL), size_(0), x(time(NULL)) {}
  MultiLL(const MultiLL<T>& old) { this->copy_list(old); }
  MultiLL& operator= (const MultiLL<T>& old);
  ~MultiLL() { this->destroy_list(); }

  // simple accessors & modifiers
  unsigned int size() const { return size_; }
  bool empty() const { return chrono_head == NULL&&sorted_head==NULL; }
  void clear() { this->destroy_list(); }

  void add(const T& v);
  
  typedef list_iterator<T> iterator;
  iterator erase(iterator itr);
  iterator begin_chronological();
  iterator end_chronological(){ return iterator(); }
  iterator begin_sorted();
  iterator end_sorted(){ return iterator(); }
  iterator begin_random();

private:
  // private helper functions
  void copy_list(const MultiLL<T>& old);
  void destroy_list();

  Node<T>* chrono_head;
  Node<T>* chrono_tail;
  Node<T>* sorted_head;
  Node<T>* sorted_tail;
  Node<T>* random_head;
  unsigned int size_;
  MTRand_int32 x;
};

// -----------------------------------------------------------------
// LIST CLASS IMPLEMENTATION

template <class T>
MultiLL<T>& MultiLL<T>::operator= (const MultiLL<T>& old) {
  if (&old != this) {
    this->destroy_list();
    this->copy_list(old);
  }
  return *this;
}

template <class T>
void MultiLL<T>::add(const T& v) {
 
	Node<T>* newp = new Node<T>(v);
	
    if (!chrono_head) {  //add the new node by the chronological order
    chrono_head = chrono_tail = newp;
  } else {
    newp->chrono_prev = chrono_tail;
    chrono_tail->chrono_next = newp;
    chrono_tail = newp;
  }
    
	if(!sorted_head){  //meantime, also add the new node by the sorted order
		sorted_head=sorted_tail=newp;
		}
	else{
		Node<T>* temp=sorted_head;
		bool judge=false;
		while(temp!=NULL){
			if(temp->value_ > newp->value_){  //insert the new node before the bigger node
				newp->sorted_prev=temp->sorted_prev;
				newp->sorted_next=temp;
				temp->sorted_prev=newp;
				if(temp==sorted_head){
					sorted_head=newp;}
				else{
					newp->sorted_prev->sorted_next=newp;
				}
				judge=true;
				break;
			}
			temp=temp->sorted_next;
		}
		if(!judge){  //if the new node is biggest, push it back and make it as the tail node
			newp->sorted_prev = sorted_tail;
			sorted_tail->sorted_next = newp;
			sorted_tail = newp;
		}
	}

	++size_;  //increment the size
}

template <class T>
typename MultiLL<T>::iterator MultiLL<T>::erase(iterator itr) {
  assert (size_ > 0);
  --size_;
    
    if (itr.ptr_ == chrono_head && chrono_head == chrono_tail) {
		chrono_head = chrono_tail = NULL;
			  
		if (itr.ptr_ == sorted_head && sorted_head == sorted_tail) {
			sorted_head = sorted_tail = NULL;
		}

		else if (itr.ptr_ == sorted_head) {
			sorted_head = sorted_head->sorted_next;
			sorted_head->sorted_prev = NULL;
		}

		else if (itr.ptr_ == sorted_tail) {
			sorted_tail = sorted_tail->sorted_prev;
			sorted_tail->sorted_next = NULL;
		}

		else {
			itr.ptr_->sorted_prev->sorted_next = itr.ptr_->sorted_next;
			itr.ptr_->sorted_next->sorted_prev = itr.ptr_->sorted_prev;
		}
    }

    else if (itr.ptr_ == chrono_head) {
		chrono_head = chrono_head->chrono_next;
		chrono_head->chrono_prev = NULL;
		
		if (itr.ptr_ == sorted_head && sorted_head == sorted_tail) {
			sorted_head = sorted_tail = NULL;
		}

		else if (itr.ptr_ == sorted_head) {
			sorted_head = sorted_head->sorted_next;
			sorted_head->sorted_prev = NULL;
		}

		else if (itr.ptr_ == sorted_tail) {
			sorted_tail = sorted_tail->sorted_prev;
			sorted_tail->sorted_next = NULL;
		}

		else {
			itr.ptr_->sorted_prev->sorted_next = itr.ptr_->sorted_next;
			itr.ptr_->sorted_next->sorted_prev = itr.ptr_->sorted_prev;
		}
    }

    else if (itr.ptr_ == chrono_tail) {
		chrono_tail = chrono_tail->chrono_prev;
		chrono_tail->chrono_next = NULL;
		
		if (itr.ptr_ == sorted_head && sorted_head == sorted_tail) {
			sorted_head = sorted_tail = NULL;
		}

		else if (itr.ptr_ == sorted_head) {
			sorted_head = sorted_head->sorted_next;
			sorted_head->sorted_prev = NULL;
		}

		else if (itr.ptr_ == sorted_tail) {
			sorted_tail = sorted_tail->sorted_prev;
			sorted_tail->sorted_next = NULL;
		}

		else {
			itr.ptr_->sorted_prev->sorted_next = itr.ptr_->sorted_next;
			itr.ptr_->sorted_next->sorted_prev = itr.ptr_->sorted_prev;
		}
    }

    else {
		itr.ptr_->chrono_prev->chrono_next = itr.ptr_->chrono_next;
		itr.ptr_->chrono_next->chrono_prev = itr.ptr_->chrono_prev;
		
		if (itr.ptr_ == sorted_head && sorted_head == sorted_tail) {
			sorted_head = sorted_tail = NULL;
		}

		else if (itr.ptr_ == sorted_head) {
			sorted_head = sorted_head->sorted_next;
			sorted_head->sorted_prev = NULL;
		}

		else if (itr.ptr_ == sorted_tail) {
			sorted_tail = sorted_tail->sorted_prev;
			sorted_tail->sorted_next = NULL;
		}

		else {
			itr.ptr_->sorted_prev->sorted_next = itr.ptr_->sorted_next;
			itr.ptr_->sorted_next->sorted_prev = itr.ptr_->sorted_prev;
		}
    }
	
	if(itr.flag==1){
	iterator result(itr.ptr_->chrono_next,1); 
	delete itr.ptr_; 
	return result;
	}
	
    if(itr.flag==2){
	iterator result(itr.ptr_->sorted_next,2); 
	delete itr.ptr_; 
	return result;
	} 
	
	if(itr.flag==3){
		Node<T>* temp =itr.ptr_;
		for(unsigned int i=0;i<size_-1;i++){
			temp=temp->random_next;
		}
		temp->random_next=itr.ptr_->random_next;
		iterator result(itr.ptr_->random_next,3);
		delete itr.ptr_;
		return result;
	}
	
    return iterator();
	
}
	

template <class T>
typename MultiLL<T>::iterator MultiLL<T>::begin_chronological() {
	return iterator(chrono_head,1);
}

template <class T>
typename MultiLL<T>::iterator MultiLL<T>::begin_sorted() {
	return iterator(sorted_head,2);
}

template <class T>
typename MultiLL<T>::iterator MultiLL<T>::begin_random() {
	int numbers[size_];
	unsigned int i=0;
	while(i<size_){  //create an array of randomly selected non-repeated numbers
		int selected=(x() % (size_));
		bool judge=true;
		for(unsigned int j=0;j<i;j++){
			if(numbers[j]==selected){
				judge=false;
				break;
			}
		}
		if(judge){
			numbers[i]=selected;
			i++;
		}
	}
		
	unsigned int count;
	for(count=0;count<size_;count++){  //according to the array, reuse the chronological order and apply it to random order
		Node<T>* chronotemp=chrono_head;
		Node<T>* randomtemp;
		for(int k=0;k<numbers[count];k++){
			chronotemp=chronotemp->chrono_next;
		}
		if(count==0){
			random_head=chronotemp;
			randomtemp=random_head;
		}
		else if(count!=size_-1){
			randomtemp->random_next=chronotemp;
			randomtemp=chronotemp;
		}
		else if(count==size_-1){
			randomtemp->random_next=chronotemp;
			randomtemp=chronotemp;
			randomtemp->random_next=random_head;  //return the last node to head node
		}
	}
		
	return iterator(random_head,3);
}

template <class T>
void MultiLL<T>::destroy_list() {
  if(size_==0){
	  return;
  }

  Node<T>* temp=chrono_head;
  while(chrono_head!=NULL){
	  temp=chrono_head->chrono_next;
	  delete chrono_head;
	  chrono_head=temp;
  }
  
  chrono_head=NULL;
  chrono_tail=NULL;
  sorted_head=NULL;
  sorted_tail=NULL;
  size_=0;
  
}

template <class T>
void MultiLL<T>::copy_list(const MultiLL<T>& old) {
  size_=old.size_;
  if (size_==0) {
    return;
  }
  
  chrono_head=new Node<T>;  //initialize
  chrono_head->value_=old.chrono_head->value_;
  chrono_tail=chrono_head;  //make tail at the head point at the beginning
  
  Node<T>* old_chrono=old.chrono_head->chrono_next;
  
  while (old_chrono!=NULL) {
    chrono_tail->chrono_next= new Node<T>;
	chrono_tail->chrono_next->value_=old_chrono->value_;
    chrono_tail->chrono_next->chrono_prev=chrono_tail;
    chrono_tail=chrono_tail->chrono_next;  //set chrono_tail
	
    old_chrono=old_chrono->chrono_next;
  }
  
  
  sorted_head=new Node<T>; 
  sorted_head->value_=old.sorted_head->value_;
  sorted_tail=sorted_head;  
  
  Node<T>* old_sorted=old.sorted_head->sorted_next;
  
  while (old_sorted!=NULL) {
    sorted_tail->sorted_next= new Node<T>;
	sorted_tail->sorted_next->value_=old_sorted->value_;
    sorted_tail->sorted_next->sorted_prev=sorted_tail;
    sorted_tail=sorted_tail->sorted_next;  
	
    old_sorted=old_sorted->sorted_next;
  }
}

#endif