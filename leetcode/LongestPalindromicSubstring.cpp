/*
   Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
   */

#include "common.h"

class Solution {
  public:
    string longestPalindrome(string s) {
      if (s.size() < 2) return s;
      int n = s.size(), maxLen = 0, start = 0;
      for (int i = 0; i < n - 1; ++i) {
        searchPalindrome(s, i, i, start, maxLen);
        searchPalindrome(s, i, i + 1, start, maxLen);
      }
      return s.substr(start, maxLen);
    }
    void searchPalindrome(string s, int left, int right, int& start, int& maxLen) {
      while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left; ++right;
      }
      if (maxLen < right - left - 1) {
        start = left + 1;
        maxLen = right - left - 1;
      }
    }
};
Solution s;

TEST(LongestPalindromicSubstring, normal) {
  ASSERT_EQ("bab", s.longestPalindrome("babad"));
}
