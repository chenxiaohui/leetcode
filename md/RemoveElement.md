
    class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            int i = 0;
            int realPos = i;
            int temp = 0;
            while (realPos < n){
                while (A[realPos] == elem){
                    realPos ++;
                }
                if (i != realPos){
                    temp = A[realPos];
                    A[realPos] = A[i];
                    A[i] = temp;
                }
                i ++;
                realPos ++;
            }
        }
    };


  实现上首先不要用n^2的复杂度去找到一个删一个，思路上要考虑就是一次原地数据筛选，每个位置安上符合筛选条件的数据。上段代码主要的问题是一些异常情况：

  1. 比如 while (A[realPos] == elem){realPos ++;} 这里可能readPos直接就溢出了。所以遇到*找到第一个不是x或者第一个是x的值的情况*，都得考虑溢出。
  
  2. i != realPos的判断，没必要交换的不要浪费时间。另外的问题是，如果这里用异或（x^=y; y^=x; x^=y）来交换，那么不判断就出错了。
