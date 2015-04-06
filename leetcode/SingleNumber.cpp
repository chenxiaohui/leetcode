
/*
 *  Given an array of integers, every element appears twice except for one. Find that single one.
 *  Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
#include "common.h"

class Solution {
public:
      int singleNumber(int A[], int n) {
        int res = 0;
        for (int i = 0; i < n; i++){
          res ^= A[i];
        }
        return res;
    }
}s;

TEST(SingleNumber, normal)
{
  int a[] = {2,2,3,5,5};
  EXPECT_EQ(3, s.singleNumber(a, sizeof(a)/sizeof(int)));
}

TEST(SingleNumber, empty)
{
  int a[] ={};
  EXPECT_EQ(0, s.singleNumber(a, 0));
}
