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
};
int main(int argc, const char *argv[])
{
  int a[] = {1,2,2,3};
  Solution d;
  copy(a, a + d.removeElement(a, 4, 2), ostream_iterator<int>(cout, " "));
  int b[] = {2,2,2,2};
  cout << d.removeElement(b, 4, 2);
  int c[] = {};
  cout << d.removeElement(b, 0, 2);
  //copy(b, b + d.removeElement(b, 4, 2), ostream_iterator<int>(cout, " "));
  return 0;
}
