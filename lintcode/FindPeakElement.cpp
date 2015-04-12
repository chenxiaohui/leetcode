/*
There is an integer array which has the following features:    * The numbers in adjacent positions are different.     * A[0] < A[1] && A[A.length - 2] > A[A.length - 1].We define a position P is a peek if A[P] > A[P-1] && A[P] > A[P+1].Find a peak element in this array. Return the index of the peak.
Note
The array may contains multiple peeks, find any of them.


Example
[1, 2, 1, 3, 4, 5, 7, 6]
return index 1 (which is number 2)  or 6 (which is number 7)


Challenge

Time complexity O(logN)


*/

#include "common.h"

class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
      int ret = -1;
      if (A.size() > 1) {
        for (int i = 1; i < static_cast<int>(A.size()) - 1; i++) {
          if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
            ret = i;
            break;
          }
        }
      } else if (A.size() == 1) {
        ret = 0;
      }
      return ret;
    }
};
Solution s;

TEST(FindPeakElement, normal) {
  vector<int> A = {1,2,1,3,4,5,7,6};
  EXPECT_EQ(1, s.findPeak(A));
}
TEST(FindPeakElement, empty)
{
  vector<int> A;
  EXPECT_EQ(-1, s.findPeak(A));
  A.push_back(1);
  EXPECT_EQ(0, s.findPeak(A));
}
TEST(FindPeakElement, flat) {
  vector<int> A = {1,2,2,1,3,4,5,7,6};
  EXPECT_EQ(7, s.findPeak(A));
}
