/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R


And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

*/

#include "common.h"

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows <= 1) return s;
        string res = "";
        int size = 2 * nRows - 2;
        for (int i = 0; i < nRows; ++i) {
            for (int j = i; j < s.size(); j += size) {
                res += s[j];
                int tmp = j + size - 2 * i;
                if (i != 0 && i != nRows - 1 && tmp < s.size()) res += s[tmp];
            }
        }
        return res;
    }
};
Solution s;

TEST(ZigZagConversion, normal) {
ASSERT_EQ("PAHNAPLSIIGYIR", s.convert("PAYPALISHIRING", 3));
}
