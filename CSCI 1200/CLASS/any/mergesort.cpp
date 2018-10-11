#include <iostream>
#include <vector>
using namespace std;

template <class T> void mergesort(vector<T>& values);
template <class T> void mergesort(int low, int high, vector<T>& values, vector<T>& scratch);
template <class T> void merge(int low, int mid, int high, vector<T>& values, vector<T>& scratch);

int main() {
  vector<double> pts(7);
  pts[0] = -45.0;  pts[1] =   89.0;  pts[2] =    34.7;  pts[3] =   21.1;
  pts[4] =   5.0;  pts[5] =  -19.0;  pts[6] =  -100.3; 

  mergesort(pts);

  for (unsigned int i=0; i<pts.size(); ++i)
    cout << i << ": " << pts[i] << endl;
}

// The driver function for mergesort.  It defines a scratch vector for temporary copies.  
template <class T>
void mergesort(vector<T>& values) {
  vector<T> scratch(values.size());
  mergesort(0, int(values.size()-1), values, scratch);
}

// Here's the actual merge sort function.  It splits the vector in
// half, recursively sorts each half, and then merges the two sorted
// halves into a single sorted interval.
template <class T>
void mergesort(int low, int high, vector<T>& values, vector<T>& scratch) {
  cout << "mergesort:  low = " << low << ", high = " << high << endl;
  if (low >= high)  //  intervals of size 0 or 1 are already sorted!
    return;
  
  int  mid = (low + high) / 2;

  mergesort(low, mid, values, scratch);
  mergesort(mid+1, high, values, scratch);
  // O(n)
  merge(low, mid, high, values, scratch);
}

// merge: O(n), where n = high-low
// Non-recursive function to merge two sorted intervals (low..mid & mid+1..high) 
// of a vector, using "scratch" as temporary copying space.  
template <class T> 
void merge(int low, int mid, int high, vector<T>& values, vector<T>& scratch) {
  cout << "merge:  low = " << low << ", mid = " << mid << ", high = " << high << endl;
  int i=low;  // "top" of pile a  [low -> mid]
  int j = mid+1; // "top" of pile b  [mid+1 -> high]
  int k=low;  // the next slot in the sorted 
              // result currently in scratch
  for ( ; k <= high ; k++) {
    // check to see if one of the piles is empty
    //if (i > mid || j > high) break;
    if (i <= mid &&
        (j > high || values[i] < values [j])) {
      scratch[k] = values[i];
      i++;
    } else {
      scratch[k] = values[j];
      j++;
    }
  } 
  // copy scratch back to values
  for (k=low ; k <= high ; k++) {  
    values[k] = scratch[k];
  }
}