#include "common.h"

class Solution {
  public:
    int binarySearch(vector<int> &array, int target) {
      int ret = -1;
      // write your code here
      if (array.size() > 0){
        int low = 0;
        int high = array.size() - 1;
        int mid = 0;
        while (low <= high){
          mid = low + (high - low) / 2;
          if (array[mid] == target) {
            ret = mid;
            break;
          }else if (array[mid] < target){
            low = mid + 1;
          }else{
            high = mid - 1;
          }
        }
      }
      return ret;
    }};
Solution s;
TEST(BinarySearch, normal)
{
  int arr[] = {1,2,3,4,5,10};
  vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
  EXPECT_EQ(2, s.binarySearch(array, 3));
  EXPECT_EQ(-1, s.binarySearch(array, 7));
}
TEST(BinarySearch, single)
{
  int arr[] = {1};
  vector<int> array(arr, arr + sizeof(arr)/sizeof(int));
  EXPECT_EQ(0, s.binarySearch(array, 1));
  EXPECT_EQ(-1, s.binarySearch(array, 7));
}

TEST(BinarySearch, abnormal)
{
  vector<int> array;
  EXPECT_EQ(-1, s.binarySearch(array, 1));
  array.push_back(1);
  EXPECT_EQ(-1, s.binarySearch(array, 2));
}

