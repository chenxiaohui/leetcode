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
    int findPeakSimple(vector<int> A) {
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
    int findPeak(vector<int> A) {
      int ret = -1;
      if (A.size() > 1) {
        int beg = 0;
        int end = A.size() - 1;
        while (beg + 1 < end) {
          int mid = beg + (end - beg) / 2;
          if (A[mid - 1] > A[mid] && A[mid] > A[mid + 1]) {
            end = mid;
          } else if (A[mid - 1] < A[mid] && A[mid] < A[mid + 1]) {
            beg = mid;
          } else if (A[mid - 1] > A[mid] && A[mid + 1] > A[mid]) {
            beg = mid;  // whatever
          } else {
            ret = mid;
            break;
          }
        }
        if (ret == -1) {
          ret = (A[beg] > A[end]) ? beg : end;
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
  EXPECT_EQ(6, s.findPeak(A));
}
TEST(FindPeakElement, empty)
{
  vector<int> A;
  EXPECT_EQ(-1, s.findPeak(A));
  A.push_back(1);
  EXPECT_EQ(0, s.findPeak(A));
}
TEST(FindPeakElement, singleIncrease) {
  vector<int> A = {1,2,3,4,5,7,8};
  EXPECT_EQ(6, s.findPeak(A));
}
TEST(FindPeakElement, singleDecrease) {
  vector<int> A = {8,7,5,4,3,2,1};
  EXPECT_EQ(0, s.findPeak(A));
}
