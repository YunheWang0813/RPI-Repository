// heapsort

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// build max heap
template<class T>
void percolateDown(vector<T>& array, int top, int end) {
  while (top * 2 + 1 < end) {
    int child = top * 2 + 1;
    if (child + 1 < end && array[child] < array[child+1])
      child++;
    if (array[top] < array[child]) {  // this opposit of binary_heap above
      swap(array[top], array[child]);
      top = child;
    }
    else 
      break;
  }

  // for (unsigned int i = 0; i < array.size(); ++i)
  //   cout << array[i] << " ";
  // cout << endl;

}

template <class T>
void heapsort(vector<T>& v) {
  int end = v.size();

  // heapify
  for (int i = (end-1)/2; i >= 0; i--) {
    percolateDown(v, i, end);
  }

  //  cout << endl;

  // sort
  while (end-1  > 0) {
    swap(v[end-1], v[0]);
    percolateDown(v, 0, end-1);
    end--;
  }
}

int main() {
  vector<int> v;

  v.push_back(7);
  v.push_back(4);
  v.push_back(1);
  v.push_back(2);
  v.push_back(5);
  v.push_back(10);
  v.push_back(3);
  v.push_back(17);
  heapsort(v);

  for (unsigned int i = 0; i < v.size(); ++i)
    cout << v[i] << " ";
  cout << endl;

  return 0;
}