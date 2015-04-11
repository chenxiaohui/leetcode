/*
The code base version is an integer and start from 1 to n. One day, someone commit a bad version in the code case, so it caused itself and the following versions are all failed in the unit tests.You can determine whether a version is bad by the following interface: Java:    public VersionControl {        boolean isBadVersion(int version);    }C++:    class VersionControl {    public:        bool isBadVersion(int version);    };Python:    class VersionControl:        def isBadVersion(version)Find the first bad version.
Note
You should call isBadVersion as few as possible. Please read the annotation in code area to get the correct way to call isBadVersion in different language. For example, Java is VersionControl.isBadVersion.


Example
Given n=5
Call isBadVersion(3), get false
Call isBadVersion(5), get true
Call isBadVersion(4), get true
return 4 is the first bad version


Challenge

Do not call isBadVersion exceed O(logn) times.


*/

#include "common.h"
#include <stdlib.h>
#include <time.h>
class VersionControl {
  public:
    static int firstBadVersion;
    static bool isBadVersion(int k) {
      return k >= firstBadVersion;
    }
    static void init(int n) {
        srand(time(NULL));
        firstBadVersion = rand() % n + 1;
        //cout << firstBadVersion <<endl;
    }
};
int VersionControl::firstBadVersion = 0;

class Solution {
public:
    /**
     * @param n: An integers.
     * @return: An integer which is the first bad version.
     */
    int findFirstBadVersion(int n) {
      int ret = 0;
      if (n >= 1) {
        int beg = 1;
        int end = n;
        while (beg + 1 < end) {
          int mid = beg + (end - beg) / 2;
          if (VersionControl::isBadVersion(mid)) {
            end = mid;
          } else {
            beg = mid;
          }
        }
        if (VersionControl::isBadVersion(beg)) {
          ret = beg;
        } else if (VersionControl::isBadVersion(end)) {
          ret = end;
        }
      }
      return ret;
    }
};
Solution s;


TEST(FirstBadVersion, normal) {
  for (int i = 1; i < 1000; i ++) {
    VersionControl::init(i);
    EXPECT_EQ(VersionControl::firstBadVersion, s.findFirstBadVersion(i));
  }
}
