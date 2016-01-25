/*
 *  see pics
 */
#include "common.h"

class Solution {
public:
  int calc_fee(int hour, int minute) {
    int fee = 2;
    if (minute > 0) {
      hour += 1;
    }
    if (hour > 0) {
      fee += 4 * (hour -1) + 3;
    }
    return fee;
  }

  int get_digit(char high, char low) {
    return (high - '0') * 10 + (low - '0');
  }

  int solution(char *E, char *L) {
    int beg_h = get_digit(E[0], E[1]);
    int beg_m = get_digit(E[3], E[4]);
    int end_h = get_digit(L[0], L[1]);
    int end_m = get_digit(L[3], L[4]);
    if (end_m < beg_m) {
      end_h --;
      end_m += 60;
    }
    return calc_fee(end_h - beg_h, end_m - beg_m);
  }
};
Solution s;
TEST(parking_fee, normal) {
  EXPECT_EQ(17, s.solution("10:00", "13:21"));
  EXPECT_EQ(9, s.solution("09:42", "11:42"));
  EXPECT_EQ(9, s.solution("09:42", "11:41"));
}
TEST(parking_fee, except) {
  EXPECT_EQ(2, s.solution("10:00", "10:00"));
  EXPECT_EQ(5, s.solution("09:42", "09:43"));
  EXPECT_EQ(9, s.solution("09:42", "10:43"));
  EXPECT_EQ(5, s.solution("09:42", "10:42"));
}
