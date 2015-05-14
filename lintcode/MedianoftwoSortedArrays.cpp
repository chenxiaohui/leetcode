/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
Example
For A = [1,2,3,4,5,6] B = [2,3,4,5], the median is 3.5
For A = [1,2,3] B = [4,5], the median is 3
 


Challenge

Time Complexity O(logn)


*/

#include "common.h"

class Solution {
  public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
      double ret = 0;
      size_t na = A.size();
      size_t nb = B.size();
      size_t n =  na + nb;
      size_t count = 0;
      int last = 0;
      int current = 0;
      size_t i = 0;
      size_t j = 0;
      if (na > 0 && nb > 0) {
        while (i < na && j < nb && count < n / 2 + 1) {
          last = current;
          if (A[i] < B[j]) {
            current = A[i++];
          } else {
            current = B[j++];
          }
          count ++;
        }
      }
      while (count < n / 2 + 1) {
        last = current;
        if (na > 0) {
          current = A[i++];
        } else if (nb > 0) {
          current = B[j++];
        }
        count ++;
      }
      if (n % 2 == 1) {
        ret = current;
      } else {
        ret = (last + current) / 2.0;
      }
      return ret;
    }
};
Solution s;

TEST(MedianoftwoSortedArrays, normalOdd) {
  vector<int> A = {1,2,3,4,5,6};
  vector<int> B = {2,3,4,5};
  EXPECT_EQ(3.5, s.findMedianSortedArrays(A, B));
}
TEST(MedianoftwoSortedArrays, normalEven) {
 vector<int> A = {1,2,3};
 vector<int> B = {4,5};
 EXPECT_EQ(3, s.findMedianSortedArrays(A, B));
}
TEST(MedianoftwoSortedArrays, singleOdd) {
 vector<int> A = {1,2,3};
 vector<int> B = {};
 EXPECT_EQ(2, s.findMedianSortedArrays(A, B));
}
TEST(MedianoftwoSortedArrays, singleEven) {
 vector<int> A = {1,2,3,4};
 vector<int> B = {};
 EXPECT_EQ(2.5, s.findMedianSortedArrays(A, B));
}
TEST(MedianoftwoSortedArrays, oneFinish) {
 vector<int> A = {1,2,3,4};
 vector<int> B = {4,5,6,7,8};
 EXPECT_EQ(4, s.findMedianSortedArrays(A, B));
}
TEST(MedianoftwoSortedArrays, single) {
 vector<int> A = {3};
 vector<int> B = {4};
 EXPECT_EQ(3.5, s.findMedianSortedArrays(A, B));
}
TEST(MedianoftwoSortedArrays, empty) {
 vector<int> A = {3};
 vector<int> B = {};
 EXPECT_EQ(3, s.findMedianSortedArrays(A, B));
}
TEST(MedianoftwoSortedArrays, allempty) {
 vector<int> A = {};
 vector<int> B = {};
 EXPECT_EQ(0, s.findMedianSortedArrays(A, B));
}
