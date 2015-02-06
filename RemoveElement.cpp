
#include "common.h"
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int real_pos = i;
        int temp = 0;
        while (real_pos < n){
            while (A[real_pos] == elem){
            	real_pos ++;
            }
            if(real_pos >= n)
              break;
            if (i != real_pos){
            	temp = A[real_pos];
            	A[real_pos] = A[i];
            	A[i] = temp;
            }
            i ++;
            real_pos ++;
        }
        return i;
    }
}s;

TEST(RemoveElement, TestRemove)
{
  int a[] = {1,2,2,3};
  EXPECT_EQ(2, s.removeElement(a, 4, 2));
  EXPECT_EQ(1, a[0]);
  EXPECT_EQ(3, a[1]);
}

TEST(RemoveElement, TestRemove2)
{
  int a[] = {2,2,2,2};
  EXPECT_EQ(0, s.removeElement(a, 4, 2));
}

