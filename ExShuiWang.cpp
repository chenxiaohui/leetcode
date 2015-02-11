/*
 *  统计结果表明，有3个发帖很多的ID，他们的发帖数目都超过了帖子总数目N的1/4。你能从发帖ID列表中快速找出他们的ID吗？
 */
#include "common.h"

class Solution {
    public:
        int* findShuiWang(int A[], int n){
            int *a = new int[3];
            int times[] = {0, 0, 0};
            int pos = -1;
            for(int i = 0; i < n; i++){
                if ((pos = find(a, times, 3, A[i])) >= 0){
                    //found
                    times[pos] ++;
                }else if (times[0] == 0) {
                    a[0] = A[i];
                    times[0] = 1;
                }
                else if (times[1] == 0){
                    a[1] = A[i];
                    times[1] = 1;
                }
                else if (times[2] == 0){
                    a[2] = A[i];
                    times[2] = 1;
                }
                else {
                    //not found and every pos has an element
                    times[0]--;
                    times[1]--;
                    times[2]--;
                }
            }
            return a;
        }
        inline int find(int a[], int times[], int n, int element){
            for(int i = 0; i < n; i++){
                if (a[i] == element && times[i] > 0)
                    return i;
            }
            return -1;
        }
}s;

TEST(ExShuiWang, testNormal)
{
    int A[] = {1,2,3,4,1,2,3};
    int* a = s.findShuiWang(A, n(A));
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
    EXPECT_EQ(a[2], 3);
    delete[] a;
}
TEST(TestExShuiWang, testRandom)
{
    int A[] = {5,5,2,2,2,3,3,3,4,4,4};
    int* a = s.findShuiWang(A, n(A));
    EXPECT_EQ(a[0], 4);
    EXPECT_EQ(a[1], 2);
    EXPECT_EQ(a[2], 3);
    delete [] a;
}
