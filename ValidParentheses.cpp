/*
 *  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * Note: The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
#include "common.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> chars;
        for(unsigned int i = 0; i < s.size(); i++){
            if(chars.empty() || ! isMatch(chars.top(), s[i])){
                chars.push(s[i]);
            }else{
                chars.pop();
            }
        }
        return chars.empty();
    }
    bool inline isMatch(const char top, const char c){
        if (top == '{' && c == '}')
            return true;
        else if (top == '(' && c == ')')
            return true;
        else if (top == '[' && c == ']')
            return true;
        return false;
    }
};
Solution s;
TEST(ValidParentheses, normal)
{
    EXPECT_EQ(true, s.isValid("()[]{}"));
    EXPECT_EQ(true, s.isValid("([{}])"));
    EXPECT_EQ(false, s.isValid("([{]}])"));
}
TEST(ValidParentheses, special)
{
    EXPECT_EQ(true, s.isValid(""));
    EXPECT_EQ(false, s.isValid(")[{}]("));
}
