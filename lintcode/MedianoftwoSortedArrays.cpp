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
      int ret = 0;
      size_t na = A.size();
      size_t nb = B.size();
      size_t n =  na + nb;
      size_t count = 0;
      int last = 0;
      int current = 0;
      if (na > 0 && nb > 0) {
        int i = 0;
        int j = 0;
        while (i < na && j < nb) {
          last = current;
          if (A[i] < B[j]) {
            i++;
            current = A[i];
          } else {
            j++;
            current = B[j];
          }
          count ++;
          if (count == n / 2 + 1) {
            break;
          }
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

      if (n & 1 == 1) {
        ret = current;
      } else {
        ret = (last + current) / 2;
      }
    }
};
Solution s;

TEST(MedianoftwoSortedArrays, normal) {
}
