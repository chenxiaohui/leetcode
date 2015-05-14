/*
 *  insert sort method
 */
#include "common.h"

class Solution {
public:
  void insertSort(int A[], int n) {
    if (n <= 1) {
      return;
    }
    for (int i = 0; i < n - 1; i++) {
      int idx = i;
      for (int j = i + 1; j < n; j++ ) {
        if (A[idx] > A[j]) {
          idx = j;
        }
      }
      if (idx != i) {
        int temp = A[idx];
        A[idx] = A[i];
        A[i] = temp;
      }
    }
  }
};
Solution s;
TEST(insertSort, normal) {
  int A[] = {5,4,3,2,1};
  int B[] = {1,2,3,4,5};
  s.insertSort(A, n(A));
  EXPECT_TRUE(equal(A, n(A), B, n(B)));
}
TEST(insertSort, equal) {
  int A[] = {5,3,3,3,1};
  int B[] = {1,3,3,3,5};
  s.insertSort(A, n(A));
  EXPECT_TRUE(equal(A, n(A), B, n(B)));
}

TEST(insertSort, single) {
  int A[] = {5};
  int B[] = {5};
  s.insertSort(A, n(A));
  EXPECT_TRUE(equal(A, n(A), B, n(B)));
}

TEST(insertSort, empty) {
  int A[] = {};
  int B[] = {};
  s.insertSort(A, n(A));
  EXPECT_TRUE(equal(A, n(A), B, n(B)));
}

