
/*
 *  Given an array of integers, every element appears three times except for one. Find that single one.
 */
#include "common.h"

class Solution {
public:

    int singleNumber(int A[], int n) {
        int ones = 0, twos = 0, xthrees = 0;
        for(int i = 0; i < n; ++i) {
            twos |= (ones & A[i]);
            ones ^= A[i];
            xthrees = ~(ones & twos);
            twos &= xthrees;
            ones &= xthrees;
        }
        return ones;
    }
};
Solution s;

TEST(SingleNumberII, normal)
{
    int A[] = {1,3,3,3,1,1,4,2,2,2};
    EXPECT_EQ(4, s.singleNumber(A, n(A)));
}
TEST(SingleNumberII, one)
{
    int A[] = {1};
    EXPECT_EQ(1, s.singleNumber(A, n(A)));
}
TEST(SingleNumberII, nothing)
{
    int A[] = {};
    EXPECT_EQ(0, s.singleNumber(A, n(A)));
}
