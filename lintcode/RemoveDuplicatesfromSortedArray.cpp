/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.Do not allocate extra space for another array, you must do this in place with constant memory.For example,Given input array A = [1,1,2],Your function should return length = 2, and A is now [1,2].
Example


*/

#include "common.h"

class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums) {
      int ret = 0;
      if (nums.size() >= 1) {
        int i = 0;
        int j = i + 1;
        while (true) {
          while (j < static_cast<int>(nums.size()) && nums[j] == nums[i]) j++;
          if (j < static_cast<int>(nums.size())) {
            nums[++i] = nums[j++];
          } else {
            break;
          }
        }
        ret = i + 1;
      }
      return ret;
    }
};
Solution s;

TEST(RemoveDuplicatesfromSortedArray, normal) {
  vector<int> nums = {1,1,1,1,2,2,2,3,3};
  EXPECT_EQ(3, s.removeDuplicates(nums));
}
TEST(RemoveDuplicatesfromSortedArray, empty)
{
  vector<int> nums;
  EXPECT_EQ(0, s.removeDuplicates(nums));
  nums.push_back(1);
  EXPECT_EQ(1, s.removeDuplicates(nums));
}
TEST(RemoveDuplicatesfromSortedArray, allSame)
{
  vector<int> nums = {1,1,1,1};
  EXPECT_EQ(1, s.removeDuplicates(nums));
}
TEST(RemoveDuplicatesfromSortedArray, allDifferent)
{
  vector<int> nums = {1,2,3,4};
  EXPECT_EQ(4, s.removeDuplicates(nums));
}
