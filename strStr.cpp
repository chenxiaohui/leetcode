/*
 *  strstr (a.k.a find sub string), is a useful function in string operation. You task is to implement this function. For a given source string and a target string, you should output the "first" index(from 0) of target string in source string. If target is not exist in source, just return -1.
 * Note: Example If source="source" and target="target", return -1. If source="abcdabcdefg" and target="bcd", return 1.
 */
#include "common.h"

class Solution {
public:
      int strStr(const char *source, const char *target) {
        // write your code here
        int pos = -1;
        if (source != NULL && target != NULL){
            int src_len = strlen(source);
            int dst_len = strlen(target);
            for (int i = 0; i < src_len - dst_len + 1; i++){
                int j = 0;
                for(; j < dst_len; j++){
                    if (target[j] != source[j + i]){
                        break;
                    }
                }
                if (j == dst_len){
                    pos = i;
                    break;
                }
            }
        }
        return pos;
      }
};
Solution s;

TEST(strStr, null)
{
    EXPECT_EQ(-1, s.strStr(NULL, "ss"));
    EXPECT_EQ(-1, s.strStr("ss", NULL));
    EXPECT_EQ(-1, s.strStr(NULL, NULL));
}
TEST(strStr, empty)
{
    EXPECT_EQ(0, s.strStr("", ""));
    EXPECT_EQ(0, s.strStr("ss", ""));
}
TEST(strStr, normal)
{
    EXPECT_EQ(-1, s.strStr("source", "target"));
    EXPECT_EQ(1, s.strStr("abcdabcdefg", "bcd"));
    EXPECT_EQ(3, s.strStr("adabcdefg", "bcd"));
}
