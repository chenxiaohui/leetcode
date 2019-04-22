/*
Given an array of integers, find two numbers such that they add up to a specific target number.The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.You may assume that each input would have exactly one solution.
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

*/

#include "common.h"

class Solution {
public:
  vector<int> TwoSum(vector<int>& nums, int target) {
    vector<int> result;
    if (nums.size() >= 2) {
      sort(nums.begin(), nums.end());
      auto beg = nums.begin();
      auto end = nums.end() - 1;
      while (beg < end) {
        auto sum = *beg + *end;
        if (sum < target) {
          beg++;
        } else if (sum > target) {
          end--;
        } else {
          result.push_back(*beg);
          result.push_back(*end);
          beg++;
          end--;
        }
      }
    }
    return result;
  }
};
Solution s;

TEST(TwoSum, normal) {
  vector<int> a = {1,3,2,4,5};
  ASSERT_TRUE(equal({1,5, 2,4}, s.TwoSum(a, 6)));
  vector<int> b = {3,3,3,4,5};
  ASSERT_TRUE(equal({3,3}, s.TwoSum(b, 6)));
}
