/*
   There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
   */

#include "common.h"

class Solution {
  public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
      int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
      return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }

    int findKth(const vector<int>& nums1, size_t i, const vector<int>& nums2, size_t j, size_t k) {
      if (i >= nums1.size()) return nums2[j + k - 1];
      if (j >= nums2.size()) return nums1[i + k - 1];
      if (k == 1) return min(nums1[i], nums2[j]);
      int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
      int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
      if (midVal1 < midVal2) {
        return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
      } else {
        return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
      }
    }
};
Solution s;

TEST(MedianofTwoSortedArrays, normal) {
  ASSERT_EQ(2.5, s.findMedianSortedArrays({1,2}, {3,4}));
}
