/*
Follow up for "Remove Duplicates":What if duplicates are allowed at most twice?For example,Given sorted array A = [1,1,1,2,2,3],Your function should return length = 5, and A is now [1,1,2,2,3].
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
      if (nums.size() > 0) {
        if (nums.size() > 1) {
          int i = 0;
          int j = 0;
          while (j < static_cast<int>(nums.size())) {
            nums[i++] = nums[j++];
            if (nums[j] == nums[j - 1]) {
              nums[i++] = nums[j++];
              while (j < static_cast<int>(nums.size()) && nums[j] == nums[j - 1]) {
                j++;
              }
            }
          }
          ret = i;
        } else {
          ret = 1;
        }
      }
      return ret;
    }
};
Solution s;

TEST(RemoveDuplicatesfromSortedArrayII, normal) {
  vector<int> nums = {1, 1, 1, 2, 2, 2};
  EXPECT_EQ(4, s.removeDuplicates(nums));
}
TEST(RemoveDuplicatesfromSortedArrayII, single)
{
  vector<int> nums = {1,2,3,4};
  EXPECT_EQ(4, s.removeDuplicates(nums));
}
TEST(RemoveDuplicatesfromSortedArrayII, doub) {
  vector<int> nums = {1, 1, 2, 2, 3, 3};
  EXPECT_EQ(6, s.removeDuplicates(nums));
}
TEST(RemoveDuplicatesfromSortedArrayII, mixed) {
  vector<int> nums = {1,1,2,2,2,3,4};
  EXPECT_EQ(6, s.removeDuplicates(nums));
}
