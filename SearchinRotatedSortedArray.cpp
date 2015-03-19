/*
 *  Suppose a sorted array is rotated at some pivot unknown to you beforehand. (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2). You are given a target value to search. If found in the array return its index, otherwise return -1. You may assume no duplicate exists in the array.
 * Note: Example For [4, 5, 1, 2, 3] and target=1, return 2 For [4, 5,1, 2, 3] and target=0, return -1
 */
#include "common.h"

class Solution {
public:
    int search(vector<int> &A, int target) {
      int ret = -1;
      int low = 0;
      int high = A.size() - 1;
      if (!A.empty()) {
        while (low + 1 < high) {
          int mid = low + (high - low) / 2;
          if (A[mid] > A[low]) {
            if (target < A[low] || target > A[mid]) {
              low = mid;
            } else {
              high = mid;
            }
          } else if (A[mid] < A[low]) {
            if (target > A[low] || target < A[mid]) {
              high = mid;
            } else {
              low = mid;
            }
          } else {
            high = mid;
          }
        }
        if (A[low] == target) {
          ret = low;
        } else if (A[high] == target) {
          ret = high;
        }
      }
      return ret;
    }
};
Solution s;
TEST(SearchinRotatedSortedArray, testNormal)
{
    int arr[] = {4,5,1,2,3};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(2, s.search(array, 1));
}
TEST(SearchinRotatedSortedArray, testNotFind)
{
    int arr[] = {4,5,1,2,3};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(-1, s.search(array, 0));
}
TEST(SearchinRotatedSortedArray, testEqual)
{
    int arr[] = {4,4,4,4,4};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(-1, s.search(array, 0));
    EXPECT_EQ(0, s.search(array, 4));
}
TEST(SearchinRotatedSortedArray, testNone)
{
    int arr[] = {};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(-1, s.search(array, 0));
}

TEST(SearchinRotatedSortedArray, testSingle)
{
    int arr[] = {4};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(-1, s.search(array, 0));
    EXPECT_EQ(0, s.search(array, 4));
}
