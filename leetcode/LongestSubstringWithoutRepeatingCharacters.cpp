/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include "common.h"

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
        int res = 0, left = -1, n = s.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            if (m.count(s[i]) && m[s[i]] > left) {
                left = m[s[i]];
            }
            m[s[i]] = i;
            res = max(res, i - left);
        }
        return res;
    }
};
Solution s;

TEST(LongestSubstringWithoutRepeatingCharacters, normal) {
  string a = "abcdd";
  ASSERT_EQ(4, s.lengthOfLongestSubstring(a));
}
