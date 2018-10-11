/////////////////////////////////////////////////////////////////////////////////////

// breadth first traversal

template <class T>
void bf(Node<T>* tree) {
  if (tree = NULL)
    return;

  std::list<Node<T>*> queue;  
  Node<T>* node;

  queue.push_back(tree);
  while (queue.size() != 0) {
    node = queue.front();
    queue.pop_front();
    std::cout << node->value << std::endl;

    if (node->left != NULL)
      queue.push_back(node->left);

    if (node->right != NULL)
      queue.push_back(node->right);
  }
}

/////////////////////////////////////////////////////////////////////////////////////////////

// destroy_tree and insert and part of the ds_set.h class definition

// destroy_tree
// post order traversal

// note: pass the pointer by reference
// so that it can be set to NULL
void destroy_tree(TreeNode<T>*& p) {
  if (p != NULL) {
    destroy_tree(p->left);
    destroy_tree(p->right);
    
    delete p;
    p = NULL;
    size_ = 0;
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////

// insert 

std::pair< iterator, bool > insert(T const& key_value) { 
  return insert(key_value, root_); 
}

std::pair<iterator,bool> insert(const T& key_value, TreeNode<T>*& p) {
  if (!p) {
    // allocate a new node and make p point to it
    p = new TreeNode<T>(key_value);
    this->size_++;                                                                    //if p->size_++ ?
    return std::pair<iterator,bool>(iterator(p), true);
  }
  else if (key_value < p->value)
    return insert(key_value, p->left);
  else if (key_value > p->value)
    return insert(key_value, p->right);
  else
    return std::pair<iterator,bool>(iterator(p), false); // we found a match, don't insert
}
 
//////////////////////////////////////////////////////////////////////////////////////////////

// tree traversal

void print_in_order(ostream& ostr, const TreeNode<T>* p) {
  if (p) {
    print_in_order(ostr, p->left);
    // visit the node - in this case print
    ostr << p->value << "\n";
    print_in_order(ostr, p->right);
  }
}

void print_pre_order(ostream& ostr, const TreeNode<T>* p) {
  if (p) {
    ostr << p->value << "\n";
    print_in_order(ostr, p->left);
    print_in_order(ostr, p->right);
  }
}

void print_psot_order(ostream& ostr, const TreeNode<T>* p) {
  if (p) {
    print_in_order(ostr, p->left);
    print_in_order(ostr, p->right);
    ostr << p->value << "\n";
  }
}

////////////////////////////////////////////////////////////////////////////////////////////

// traversal without recursion

void print_in_order(ostream& ostr, const TreeNode<T>* root) {
  std::vector<TreeNode<T>*> stack;

  // save the left nodes
  TreeNode<T>* curr = root;
  while (curr != NULL) {
    stack.push_back(curr);
    curr = curr->left;
  }

  while (stack.size() != 0) {
    curr = stack.back();  // remove the last element from the stack
    stack.pop_back();
    ostr << p->value << "\n";  // viti the node

    // find the left most child of the right child
    curr = curr-right;
    while (curr != NULL) {
      stack.push_back(curr);
      curr = curr->left;
    }    
  }
}


void print_pre_order(ostream& ostr, const TreeNode<T>* root) {
  std::vector<TreeNode<T>*> stack;

  TreeNode<T>* curr = root;
  stack.push_back(curr);

  while (stack.size() != 0) {
    TreeNode<T>* curr = stack.back();
    stack.pop_back();
    ostr << p->value << "\n";
    
    if (curr->right != NULL)
      stack.push_back(curr->right);
    if (curr->left != NULL)
      stack.push_back(curr->left);
  }
}
  
// post order requires keeping track of whether a node has been visited before
void print_post_order(ostream& ostr, const TreeNode<T>* root) {
  std::vector<TreeNode<T>*> stack;
  std::vector<bool> visit_stack;

  TreeNode<T>* curr = root;
  while (curr != NULL) {
    stack.push_back(curr);
    visit_stack.push_back(false);
    curr = curr->left;
  }

  while (stack.size() != 0) {
    curr = stack.back();  // remove the last element from the stack

    bool already_seen = visit_stack.back();
    if (already_seen) {
      ostr << p->value << "\n";
      stack.pop_back();
      visit_stack.pop_back();
    }
    else {
      visit_stack.pop_back();
      visit_stack.push_back(true);

      curr = curr-right;
      while (curr != NULL) {
	stack.push_back(curr);
	visit_stack.push_back(false);
	curr = curr->left;
      }    
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////

// pre-increment iterator ++itr
// similar to in-order traversal
tree_iterator<T> & operator++() {
  if (ptr_->right_ != NULL) {
    // find the smallest value to the right
    ptr_ = ptr_-> right_;
    while (ptr_-> left_) {
      ptr_ = ptr_-> left_;               
    }
  } 
  else {
    // no children to the right...

    // (find a node that's bigger than the current one)

    TreeNode<T>* p = ptr_->parent;
    while (p != NULL && ptr_ == p->right) {
      ptr_ = p;
      p = p->parent;
    }
    
    ptr_ = p;
  }
  
  return *this;
}

//////////////////////////////////////////////////////////////////

// post-incrment operator itr++

tree_iterator<T> & operator++(int) {
  tree_iterator<T> temp(*this);
  ++(*this);
  return temp;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// iterator using a stack

// stack is private member of tree_iterator class
 std::vector<TreeNode<T>*> stack;

// begin finds leftmost node
tree_iterator<T> & begin() {
  stack.clear();
  TreeNode<T>* p = root_;
  while (p != NULL) {
    stack.push_back(p);
    p = p->left;
  }

  p = stack.back();
  stack.pop_back();

  return iterator(p);
}

tree_iterator<T> & operator++() {
  if (stack.size() == 0)
    return iterator(NULL);

  // get next node from stack
  p = stack.back();
  stack.pop_back();
  
  // find leftmost child of right child
  if (p->right != NULL) {
    TreeNode<T>* curr = p->right;
    while (curr != NULL) {
      stack.push_back(curr);
      curr = curr->left;
    }
  }
  
  return iterator(p);
}

