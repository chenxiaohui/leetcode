
/*
 *  uniq an array, may not be sorted
 */
#include "common.h"

class Solution {
public:
  int uniq(int* array, int n) {
    int ret = n;
    if (n > 1) {
      sort(array, array + n);
      int i = 0;
      int j = 0;
      while (true) {
        int cur = array[j];
        while (j < n && array[j++] == cur);
        if (j < n) {
          array[++i] = array[j];
        } else {
          break;
        }
      }
      ret = i + 1;
    }
    return ret;
  }
};

//Solution s;
//TEST(Uniq, normal) {
  //int a[] = {4,4,3,3,2,2,1,1};
  //EXPECT_EQ(4, s.uniq(a, n(a)));
  //int b[] = {1,2,3,4};
  //EXPECT_TRUE(a, 4, b, n(b));
//}

//TEST(Uniq, single) {
  //int a[] = {4};
  //EXPECT_EQ(1, s.uniq(a, n(a)));
  //print(a, n(a));
//}

