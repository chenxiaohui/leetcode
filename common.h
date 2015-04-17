#include <iostream>
#include <iterator>
#include <algorithm>
#include <stack>
#include <string>
#include <gtest/gtest.h>

using namespace std;

#define n(A) sizeof(A)/sizeof(int)

template <typename T>
bool equal(const vector<T>& A, const vector<T>& B) {
  bool ret = false;
  if (A.size() == B.size()) {
    size_t na = A.size();
    if (na == 0) {
      ret = true;
    } else {
      size_t i = 0;
      while (A[i] == B[i] && i < na) {
        i++;
      }
      if (i == na) {
        ret = true;
      }
    }
  }
  return ret;
}

template <typename T>
bool equal(const T* A, int na, const T* B, int nb) {
  bool ret = false;
  if (na == nb) {
    if (na == 0) {
      ret = true;
    } else {
      int i = 0;
      while (A[i] == B[i] && i < na) {
        i++;
      }
      if (i == na) {
        ret = true;
      }
    }
  }
  return ret;
}
template<typename T>
void print(const vector<T>& ve){
   cout << "[";
   copy(ve.begin(), ve.end(), ostream_iterator<T>(cout, ","));
   cout <<"]" <<endl;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
