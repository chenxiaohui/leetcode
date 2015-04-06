/*
 *  Follow up for "Search in Rotated Sorted Array": What if duplicates are allowed? Would this affect the run-time complexity? How and why? Write a function to determine if a given target is in the array.
 * Note: Example
 */
#include "common.h"

class Solution {
public:
    bool search(vector<int> &A, int target) {
        bool found = false;
        if (A.size() > 0) {
          int low = 0;
          int high = A.size() - 1;
          while (low + 1 < high) {
            int mid = low + (high - low) / 2;
            if (A[mid] > A[low]) {
              if (target < A[mid] && target > A[low]) {
                high = mid;
              } else if (target == A[mid] || target == A[low]) {
                found = true;
                break;
              } else {
                low = mid;
              }
            } else if (A[mid] < A[low]) {
              if (target > A[mid] && target < A[low]) {
                low = mid;
              } else if (target == A[mid] || target == A[low]) {
                found = true;
                break;
              } else {
                high = mid;
              }
            } else if (A[mid] == target) {
              found = true;
              break;
            } else {
              low = mid;
            }
          }
          if (A[low] == target || A[high] == target) {
            found = true;
          }
        }
        return found;
    }
};
Solution s;
TEST(SearchinRotatedSortedArray, testNormal)
{
    int arr[] = {4,5,1,2,3};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_TRUE(s.search(array, 1));
}
TEST(SearchinRotatedSortedArray, testNotFind)
{
    int arr[] = {4,5,1,2,3};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_FALSE(s.search(array, 0));
}
TEST(SearchinRotatedSortedArray, testEqual)
{
    int arr[] = {4,4,4,4,4};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_FALSE(s.search(array, 0));
    EXPECT_TRUE(s.search(array, 4));
}
TEST(SearchinRotatedSortedArray, testNone)
{
    int arr[] = {};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_FALSE(s.search(array, 0));
}

TEST(SearchinRotatedSortedArray, testSingle)
{
    int arr[] = {4};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_FALSE(s.search(array, 0));
    EXPECT_TRUE(s.search(array, 4));
}
TEST(SearchinRotatedSortedArray, testError)
{
    int arr[] = {1,1,3};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
    EXPECT_TRUE(s.search(array, 3));
}
