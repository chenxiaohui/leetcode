/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.
Note
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are mand n respectively.


Example
A = [1, 2, 3, empty, empty] B = [4,5]
After merge, A will be filled as [1,2,3,4,5]


*/

#include "common.h"

class Solution {
public:
    /**
     * @param A: sorted integer array A which has m elements, 
     *           but size of A is m+n
     * @param B: sorted integer array B which has n elements
     * @return: void
     */
    void mergeSortedArray(int A[], int m, int B[], int n) {
      int i = m - 1;
      int j = n - 1;
      int k = m + n - 1;
      if (m > 0 & n > 0) {
        while (i >= 0 && j >= 0) {
          if (A[i] > B[j]) {
            A[k--] = A[i--];
          } else {
            A[k--] = B[j--];
          }
        }
      }
      while (i >= 0) {
        A[k--] = A[i--];
      }
      while (j >= 0) {
        A[k--] = B[j--];
      }
    }
};
Solution s;

TEST(MergeSortedArrayII, normal) {
  int A[] = {1,2,3,0,0};
  int B[] = {4,5};
  s.mergeSortedArray(A, 3, B, n(B));
  int C[] = {1,2,3,4,5};
  EXPECT_TRUE(equal(A, 5, C, 5));
}
TEST(MergeSortedArrayII, mixed) {
  int A[] = {1,2,3,4,5,0,0};
  int B[] = {2,4};
  s.mergeSortedArray(A, 5, B, n(B));
  int C[] = {1,2,2,3,4,4,5};
  EXPECT_TRUE(equal(A, 7, C, 7));
}
TEST(MergeSortedArrayII, AEmpty) {
  int A[] = {0,0};
  int B[] = {1,2};
  s.mergeSortedArray(A, 0, B, n(B));
  int C[] = {1,2};
  EXPECT_TRUE(equal(A, 2, C, 2));
}
TEST(MergeSortedArrayII, BEmpty) {
  int A[] = {};
  int B[] = {};
  s.mergeSortedArray(A, 0, B, n(B));
  int C[] = {};
  EXPECT_TRUE(equal(A, 0, C, 0));
}
