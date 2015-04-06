/*
 *  Given a sorted array of integers, find the starting and ending position of a given target value. Your algorithm's runtime complexity must be in the order of O(log n). If the target is not found in the array, return [-1, -1].
 * Note: Example Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].
 */
#include "common.h"

class Solution {
  public:
    vector<int> searchRange(vector<int> &A, int target) {
      // write your code here
      vector<int> out;
      int start = -1;
      int end = -1;
      if (!A.empty()) {
        start = searchLeft(A, target);
        end = searchRight(A, target);
      }
      out.push_back(start);
      out.push_back(end);
      return out;
    }
    int searchLeft(vector<int> &A, int target) {
      int ret = -1;
      int start = 0;
      int end = A.size() - 1;
      int mid = 0;
      while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (A[mid] == target) {
          end = mid;
        } else if (A[mid] < target) {
          start = mid;
        } else {
          end = mid;
        }
      }
      if (A[start] == target) {
        ret = start;
      } else if (A[end] == target) {
        ret = end;
      }
      return ret;
    }
    int searchRight(vector<int> &A, int target) {
      int ret = -1;
      int start = 0;
      int end = A.size() - 1;
      int mid = 0;
      while (start + 1 < end) {
        mid = start + (end - start) / 2;
        if (A[mid] == target) {
          start = mid;
        } else if (A[mid] < target) {
          start = mid;
        } else {
          end = mid;
        }
      }
      if (A[end] == target) {
        ret = end;
      } else if (A[start] == target) {
        ret = start;
      }
      return ret;
    }
};
Solution s;
TEST(SearchforaRange, testNormal)
{
  int a[] = {5,7,7,8,8,10};
  vector<int> input(a, a + n(a));
  vector<int> ret = s.searchRange(input, 8);
  EXPECT_EQ(ret[0], 3);
  EXPECT_EQ(ret[1], 4);
}

TEST(SearchforaRange, testEmpty)
{
  int a[] = {};
  vector<int> input(a, a + n(a));
  vector<int> ret = s.searchRange(input, 8);
  EXPECT_EQ(ret[0], -1);
  EXPECT_EQ(ret[1], -1);
}
TEST(SearchforaRange, testStart)
{
  int a[] = {1,1,1,1,1,2};
  vector<int> input(a, a + n(a));
  vector<int> ret = s.searchRange(input, 1);
  EXPECT_EQ(ret[0], 0);
  EXPECT_EQ(ret[1], 4);
}
TEST(SearchforaRange, testNotFound)
{
  int a[] = {1,1,1,1,1,2};
  vector<int> input(a, a + n(a));
  vector<int> ret = s.searchRange(input, 3);
  EXPECT_EQ(ret[0], -1);
  EXPECT_EQ(ret[1], -1);
}

TEST(SearchforaRange, testEnd)
{
  int a[] = {2,1,1,1,1,1};
  vector<int> input(a, a + n(a));
  vector<int> ret = s.searchRange(input, 1);
  EXPECT_EQ(ret[0], 1);
  EXPECT_EQ(ret[1], 5);
}

TEST(SearchforaRange, testSingle)
{
  int a[] = {1};
  vector<int> input(a, a + n(a));
  vector<int> ret = s.searchRange(input, 1);
  EXPECT_EQ(ret[0], 0);
  EXPECT_EQ(ret[1], 0);
}
