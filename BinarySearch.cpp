/*
 *  Binary search is a famous question in algorithm. For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity. If the target number does not exist in the array, return -1.
 * Note: Example If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2. Challenge If the count of numbers is bigger than MAXINT, can your code work properly?
 */
#include "common.h"

class Solution {
public:
  int binarySearch(vector<int> &array, int target) {
        int ret = -1;
        if (array.size() > 0)
        {
            int low = 0;
            int high = array.size() - 1;
            int mid = 0;
            while(low <= high)
            {
                mid = low + (high - low)/2;
                if (array[mid] > target){
                    high = mid - 1;
                }else (array[mid] < target){
                    low = mid + 1;
                }else{
                    ret = mid;
                    break;
                }
            }
        }
        // write your code here
        return ret;
    }};
Solution s;
TEST(BinarySearch, normal)
{
    vector<int> array = {1, 2,3,3,4,5,10};
    EXPECT_EQ(2, s.binarySearch(array, 3));
}
TEST(BinarySearch, abnormal)
{
    vector<int> array;
    EXPECT_EQ(-1, s.binarySearch(array, 1));
    array.push_back(1);
    EXPECT_EQ(-1, s.binarySearch(array, 2));
}

