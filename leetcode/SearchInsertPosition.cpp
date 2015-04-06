/*
 *  Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order. You may assume no duplicates in the array.
 * Note: Example [1,3,5,6], 5 → 2 [1,3,5,6], 2 → 1 [1,3,5,6], 7 → 4 [1,3,5,6], 0 → 0
 */
#include "common.h"

class Solution {
public:
    int searchInsert(vector<int> &A, int target) {
        int ret = 0;
        int low = 0;
        int high = A.size() -1;
        int mid = 0;
        if (!A.empty()) {
          while (low + 1 < high) {
            mid = low + (high - low) / 2;
            if (A[mid] == target) {
              high = mid;
            } else if (A[mid] < target) {
              low = mid;
            } else {
              high = mid;
            }
          }
          if (A[low] == target) {
            ret = low;
          } else if (A[high] == target) {
            ret = high;
          } else if (target < A[low]) {
            ret = 0;
          } else if (target < A[high]) {
            ret = high;
          } else {
            ret = high + 1;
          }
        }
        return ret;
    }
};
Solution s;

TEST(SearchInsertPosition, testFind)
{
    int arr[] = {1,3,5,6};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(2, s.searchInsert(array, 5));
}
TEST(SearchInsertPosition, testNotFindSpan)
{
    int arr[] = {1,3,5,6};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(1, s.searchInsert(array, 2));
}
TEST(SearchInsertPosition, testNotFindEnd)
{
    int arr[] = {1,3,5,6};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(4, s.searchInsert(array, 7));
}
TEST(SearchInsertPosition, testNotFindBegin)
{
    int arr[] = {1,3,5,6};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(0, s.searchInsert(array, 0));
}
TEST(SearchInsertPosition, testEmpty)
{
    int arr[] = {};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(0, s.searchInsert(array, 5));
}
TEST(SearchInsertPosition, testSingle)
{
    int arr[] = {1};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_EQ(0, s.searchInsert(array, 1));
    EXPECT_EQ(1, s.searchInsert(array, 2));
    EXPECT_EQ(0, s.searchInsert(array, 0));
}
