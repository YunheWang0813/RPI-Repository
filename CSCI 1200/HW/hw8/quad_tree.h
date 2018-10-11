// ===================================================================
//
// We provide the Point class and the implementation of several
// QuadTree member functions for printing.  
//
// IMPORTANT: You should modify this file to add all of the necessary
// functionality for the QuadTree class and its helper classes: Node,
// DepthIterator, and BreadthIterator.
//
// ===================================================================

#ifndef quad_tree_h_
#define quad_tree_h_

#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>


// ==============================================================
// ==============================================================
// A tiny templated class to store 2D coordinates.  This class works
// with number_type = int, float, double, unsigned char (a 1 byte=8
// bit integer), short (a 2 byte=16 bit integer).

int maxval(int a, int b, int c, int d){			//use in height() function, to find the max value among 4 integer
	std::vector<int> vt;
	vt.push_back(a);
	vt.push_back(b);
	vt.push_back(c);
	vt.push_back(d);
	int maxim=a;
	for(int i=1;i<4;i++){
		if(vt[i]>maxim){
			maxim=vt[i];
		}
	}
	return maxim;
}

template <class number_type>
class Point {
public:
  Point() : x(0),y(0) {}
  Point(const number_type& x_, const number_type& y_) : x(x_),y(y_) {}
  // REPRESENTATION
  number_type x;
  number_type y;
};

// a helper function to print Points to STL output stream
template <class number_type>
inline std::ostream& operator<<(std::ostream &ostr, const Point<number_type> &pt) {
  ostr << "(" << pt.x << "," << pt.y << ")";
  return ostr;
}

// -------------------------------------------------------------------
// TREE NODE CLASS 
template <class number_type, class label_type>
class Node {
public:
  Node() {}
  Node(const Point<number_type>& p, const label_type& l) : pt(p), label(l), parent(NULL) {
	  for(int i=0;i<4;i++){
		children[i]=NULL;
	  }
  }
  Point<number_type> pt;
  label_type label;
  Node<number_type, label_type>* children[4];
  Node<number_type, label_type>* parent;
};

template <class number_type, class label_type> class QuadTree;

// -------------------------------------------------------------------

// NODE ITERATOR CLASS
template <class number_type, class label_type>
class DepthIterator {
public:
  DepthIterator() : ptr(NULL) {}
  DepthIterator(Node<number_type, label_type>* p) : ptr(p) {}
  DepthIterator(const DepthIterator& old) : ptr(old.ptr) {}
  ~DepthIterator() {}
  DepthIterator& operator=(const DepthIterator& old) { ptr = old.ptr;  return *this; }
  // operator* gives constant access to the value at the pointer
  const Point<number_type>& operator*() const { return ptr->pt; }
  // comparions operators are straightforward
  bool operator== (const DepthIterator& rgt) { return ptr == rgt.ptr; }
  bool operator!= (const DepthIterator& rgt) { return ptr != rgt.ptr; }
  // increment & decrement will be discussed in Lecture 19 and Lab 11
  const label_type& getLabel() const {return ptr->label;}
  
  int getDepth() const{			//find depth by counting the number of recursive parents
	Node<number_type, label_type>* temp=ptr;
	int depth=-1;
	while(temp!=NULL){
		temp=temp->parent;
		depth++;
	}
	return depth;
  }
  
  DepthIterator<number_type, label_type> & operator++() {
  int childn=-1;		//to check the children index of the specific Node, avoiding infinite loop
  while(ptr!=NULL){
	  if(ptr->children[0]!=NULL&&childn==-1){
		  ptr=ptr->children[0];
		  return *this;
	  }
	  if(ptr->children[1]!=NULL&&childn<=0){
		  ptr=ptr->children[1];
		  return *this;
	  }
	  if(ptr->children[2]!=NULL&&childn<=1){
		  ptr=ptr->children[2];
		  return *this;
	  }
	  if(ptr->children[3]!=NULL&&childn<=2){
		  ptr=ptr->children[3];
		  return *this;
	  }
	  if(ptr->parent!=NULL){
	  for(int i=0;i<4;i++){		//change the childn
		 if(ptr->parent->children[i]==ptr){
			 childn=i;
			 break;
		 } 
	  }
	  }
	  ptr=ptr->parent;		//backtrack to the parent Node
  }
  
  return *this;
}

DepthIterator<number_type, label_type> operator++(int) {
  DepthIterator<number_type, label_type> temp(*this);
  ++(*this);
  return temp;
}

private:
  // representation
  Node<number_type, label_type>* ptr;
};

template <class number_type, class label_type>
class BreadthIterator {
public:
  BreadthIterator() : ptr(NULL),firstly(true) {}
  BreadthIterator(Node<number_type, label_type>* p) : ptr(p),firstly(true){}
  BreadthIterator(const BreadthIterator& old) : ptr(old.ptr) {}
  ~BreadthIterator() {}
  BreadthIterator& operator=(const BreadthIterator& old) { ptr = old.ptr;  return *this; }
  // operator* gives constant access to the value at the pointer
  const Point<number_type>& operator*() const { return ptr->pt; }
  // comparions operators are straightforward
  bool operator== (const BreadthIterator& rgt) { return ptr == rgt.ptr; }
  bool operator!= (const BreadthIterator& rgt) { return ptr != rgt.ptr; }
  const label_type& getLabel() const {return ptr->label;}
  
  int getDepth() const{
	Node<number_type, label_type>* temp=ptr;
	int depth=-1;
	while(temp!=NULL){
		temp=temp->parent;
		depth++;
	}
	return depth;
  }
  
  BreadthIterator<number_type, label_type> & operator++() {
  if(firstly){		//initialize the "queue"
	  q.push(ptr);
	  firstly=false;
  }
  if(!q.empty()){
	  Node<number_type, label_type>* n=q.front();
	  if(n->children[0]!=NULL){
		  q.push(n->children[0]);
	  }
	  if(n->children[1]!=NULL){
		  q.push(n->children[1]);
	  }
	  if(n->children[2]!=NULL){
		  q.push(n->children[2]);
	  }
	  if(n->children[3]!=NULL){
		  q.push(n->children[3]);
	  }
	  q.pop();
	  if(!q.empty()){
		ptr=q.front();
	  }
	  else{
		  ptr=NULL;
	  }
  }
  return *this;
}

BreadthIterator<number_type, label_type> operator++(int) {
  BreadthIterator<number_type, label_type> temp(*this);
  ++(*this);
  return temp;
}

private:
  // representation
  Node<number_type, label_type>* ptr;
  std::queue<Node<number_type, label_type>*> q;
  bool firstly;
};


// -------------------------------------------------------------------
// QuadTree CLASS
template <class number_type, class label_type>
class QuadTree {
public:
  QuadTree() : root_(NULL), size_(0) {}
  QuadTree(const QuadTree<number_type,label_type>& old) : size_(old.size_) { 
    root_ = this->copy_tree(old.root_); }
  ~QuadTree() { this->destroy_tree(root_);  root_ = NULL; }
  QuadTree& operator=(const QuadTree<number_type,label_type>& old) {
    if (&old != this) {
      this->destroy_tree(root_);
      root_ = this->copy_tree(old.root_);
      size_ = old.size_;
    }
    return *this;
  }

  typedef DepthIterator<number_type, label_type> iterator;		//define two types of iterators
  typedef BreadthIterator<number_type, label_type> bf_iterator;

  unsigned int size() const { return size_; }
  int height() { return height(root_);}
  bool operator==(const QuadTree<number_type,label_type>& old) const { return (old.root_ == this->root_); }

  // FIND, INSERT & ERASE
  iterator find(const number_type& tempx, const number_type& tempy) { return find(tempx, tempy, root_); }
  std::pair< iterator, bool > insert(const Point<number_type>& pt, const label_type& l) { return insert(pt, l, root_, root_); }

  // ITERATORS
  iterator begin() const { 
    if (!root_) return iterator(NULL);
    return iterator(root_);
  }
  iterator end() const { return iterator(NULL); }
  
  bf_iterator bf_begin() const { 
    if (!root_) return bf_iterator(NULL);
    return bf_iterator(root_);
  }
  bf_iterator bf_end() const { return bf_iterator(NULL); }
  
  
// ==============================================================
// PROVIDED CODE : QUAD TREE MEMBER FUNCTIONS FOR PRINTING
// ==============================================================

// NOTE: this function only works for quad trees with non negative
// integer coordinates and char labels

// NOTE2: this function assumes that no two points have the same x
// coordinate or the same y coordinate.

// plot driver function
// takes in the maximum x and y coordinates for these data points
// the optional argument draw_lines defaults to true
  
  void plot(int max_x, int max_y, bool draw_lines=true) const {
  // allocate blank space for the center of the board
  std::vector<std::string> board(max_y+1,std::string(max_x+1,' '));
  // edit the board to add the point labels and draw vertical and
  // horizontal subdivisions
  plot(root_,board,0,max_x,0,max_y,draw_lines);
  // print the top border of the plot
  std::cout << "+" << std::string(max_x+1,'-') << "+" << std::endl;
  for (int i = 0; i <= max_y; i++) {
    // print each row of the board between vertical border bars
    std::cout << "|" << board[i] << "|" << std::endl;
  }
  // print the top border of the plot
  std::cout << "+" << std::string(max_x+1,'-') << "+" << std::endl;
}

// actual recursive function for plotting
void plot(Node<number_type,label_type> *p, std::vector<std::string> &board,
          int x_min, int x_max, int y_min, int y_max, bool draw_lines) const {
  // base case, draw nothing if this node is NULL
  if (p == NULL) return;
  // check that the dimensions range of this node make sense
  assert (x_min >= 0 && x_min <= x_max);
  assert (y_min >= 0 && y_min <= y_max);
  assert (board.size() >= y_max);
  assert (board[0].size() >= x_max);
  // verify that the point stored at this node fits on the board
  assert (p->pt.y >= 0 && p->pt.y < board.size());
  assert (p->pt.x >= 0 && p->pt.x < board[0].size());
  // draw the vertical and horizontal bars extending across the
  // range of this node
  if (draw_lines) {
    for (int x = x_min; x <= x_max; x++) {
      board[p->pt.y][x] = '-';
    }
    for (int y = y_min; y <= y_max; y++) {
      board[y][p->pt.x] = '|';
    }
  }
  // draw this label
  board[p->pt.y][p->pt.x] = p->label;
  // recurse on the 4 children
  plot(p->children[0],board,x_min ,p->pt.x-1,y_min ,p->pt.y-1,draw_lines);
  plot(p->children[1],board,p->pt.x+1,x_max ,y_min ,p->pt.y-1,draw_lines);
  plot(p->children[2],board,x_min ,p->pt.x-1,p->pt.y+1,y_max ,draw_lines);
  plot(p->children[3],board,p->pt.x+1,x_max ,p->pt.y+1,y_max ,draw_lines);
}


// ==============================================================

// prints all of the tree data with a pre-order (node first, then
// children) traversal of the tree structure

// driver function
void print_sideways() const { print_sideways(root_,""); }

// actual recursive function
void print_sideways(Node<number_type,label_type>* p, const std::string &indent) const {
  // base case
  if (p == NULL) return;
  // print out this node
  std::cout << indent << p->label << " (" << p->pt.x << "," << p->pt.y << ")" << std::endl;
  // recurse on each of the children trees
  // increasing the indentation
  print_sideways(p->children[0],indent+"  ");
  print_sideways(p->children[1],indent+"  ");
  print_sideways(p->children[2],indent+"  ");
  print_sideways(p->children[3],indent+"  ");
}

// ==============================================================
// ==============================================================

private:
  // REPRESENTATION
  Node<number_type,label_type>* root_;
  unsigned int size_;
 

  // PRIVATE HELPER FUNCTIONS  
  Node<number_type,label_type>* copy_tree(Node<number_type,label_type>* old_root) {
	if(old_root==NULL){
		return NULL;
	}
	Node<number_type,label_type>* temp=new Node<number_type,label_type>;
	temp->pt.x=old_root->pt.x;
	temp->pt.y=old_root->pt.y;
	temp->label=old_root->label;
	temp->children[0]=copy_tree(old_root->children[0]);
	temp->children[1]=copy_tree(old_root->children[1]);
	temp->children[2]=copy_tree(old_root->children[2]);
	temp->children[3]=copy_tree(old_root->children[3]);
	return temp;

  }  
  
  int height(Node<number_type, label_type>* p) {
	  if(!p){
		  return -1;
	  }
	  return 1 + maxval(height(p->children[0]), height(p->children[1]), height(p->children[2]), height(p->children[3]) );
  }

// note: pass the pointer by reference
// so that it can be set to NULL
  void destroy_tree(Node<number_type,label_type>* p) { 
  if(p!=NULL){
	destroy_tree(p->children[0]);
	destroy_tree(p->children[1]);
	destroy_tree(p->children[2]);
	destroy_tree(p->children[3]);
	delete p;
	p=NULL;
	size_=0;
  }
  }

  iterator find(const number_type& tempx, const number_type& tempy, Node<number_type, label_type>*& p) {
    if (!p) {return iterator(NULL);}
    else if (tempx < p->pt.x && tempy < p->pt.y){
      return find(tempx, tempy, p->children[0]);
	}
    else if (tempx > p->pt.x && tempy < p->pt.y){
      return find(tempx, tempy, p->children[1]);
	}
    else if (tempx < p->pt.x && tempy > p->pt.y){
      return find(tempx, tempy, p->children[2]);
	}
    else if (tempx > p->pt.x && tempy > p->pt.y){
      return find(tempx, tempy, p->children[3]);
	}
    else
      return iterator(p);
  }
  
  std::pair< iterator, bool > insert(Point<number_type> poi, label_type la, Node<number_type, label_type>*& p, Node<number_type, label_type>* pare) {
    if (p==NULL) {
      p = new Node<number_type, label_type>(poi,la);
	  p->parent=pare;
      size_++;
	  return std::pair<iterator,bool>(iterator(p), true);
    }
    else if (poi.x < p->pt.x && poi.y < p->pt.y){
	  pare=p;
      return insert(poi, la ,p->children[0],pare);
	}
    else if (poi.x > p->pt.x && poi.y < p->pt.y){
	  pare=p;
      return insert(poi, la ,p->children[1],pare);
	}
    else if (poi.x < p->pt.x && poi.y > p->pt.y){
	  pare=p;
      return insert(poi, la ,p->children[2],pare);
	}
    else if (poi.x > p->pt.x && poi.y > p->pt.y){
	  pare=p;
      return insert(poi, la ,p->children[3],pare);
	}
    else{
      return std::pair<iterator,bool>(iterator(p), false);
	}
  }
  
};

#endif
