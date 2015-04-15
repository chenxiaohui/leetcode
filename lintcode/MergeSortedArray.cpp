/*
Merge two given sorted integer array A and B into a new sorted integer array.
Example
A=[1,2,3,4]
B=[2,4,5,6]
return [1,2,2,3,4,4,5,6]


Challenge

How can you optimize your algorithm if one array is very large and the other is very small?


*/

#include "common.h"

class Solution {
public:
    /**
     * @param A and B: sorted integer array A and B.
     * @return: A new sorted integer array
     */
    vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
      vector<int> result;
      int i = 0;
      int j = 0;
      int na = static_cast<int>(A.size());
      int nb = static_cast<int>(B.size());
      if (na > 0 && nb > 0) {
        while (i < na && j < nb) {
          if (A[i] < B[j]) {
            result.push_back(A[i]);
            i++;
          } else {
            result.push_back(B[j]);
            j++;
          }
        }
      }
      if (i < na) {
        while (i < na) {
          result.push_back(A[i]);
          i++;
        }
      } else if (j < nb) {
        while (j < nb) {
          result.push_back(B[j]);
          j++;
        }
      }
      return result;
    }
};
Solution s;

TEST(MergeSortedArray, normal) {
  vector<int> A = {1, 2, 3, 4};
  vector<int> B = {2, 4, 5, 6};
  vector<int> exp = {1,2,2,3,4,4,5,6};
  EXPECT_TRUE(equal(exp, s.mergeSortedArray(A, B)));
}
TEST(MergeSortedArray, empty) {
  vector<int> A;
  vector<int> B;
  vector<int> C;
  EXPECT_TRUE(equal(C, s.mergeSortedArray(A, B)));
}
TEST(MergeSortedArray, singleEmpty) {
  vector<int> A = {1, 2, 3, 4};
  vector<int> B;
  EXPECT_TRUE(equal(A, s.mergeSortedArray(A, B)));
}
