/*
Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties:    * Integers in each row are sorted from left to right.    * The first integer of each row is greater than the last integer of the previous row.
Example
Consider the following matrix:
[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
Given target = 3, return true.


Challenge

O(log(n) + log(m)) time


*/

#include "common.h"

class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
  bool searchMatrix(vector<vector<int> > &matrix, int target) {
    bool found = false;
    if (matrix.size() > 0 && matrix[0].size() > 0) {
      int i = matrix.size() - 1;
      int j = 0;
      while (!found && i >= 0 && j < static_cast<int>(matrix[0].size())) {
        if (matrix[i][j] < target) {
          j++;
        } else if (matrix[i][j] > target) {
          i--;
        } else {
          found = true;
        }
      }
    }
    return found;
  }
};
Solution s;

TEST(Searcha2DMatrix, normal) {
  vector<vector<int> > matrix = {
    {1, 3, 5, 7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
  };
  EXPECT_TRUE(s.searchMatrix(matrix, 3));
  EXPECT_FALSE(s.searchMatrix(matrix, 6));
  EXPECT_FALSE(s.searchMatrix(matrix, 51));
  EXPECT_FALSE(s.searchMatrix(matrix, 0));
}
TEST(Searcha2DMatrix, empty)
{
  vector<vector<int> > matrix;
  EXPECT_FALSE(s.searchMatrix(matrix, 3));
}
TEST(Searcha2DMatrix, oneline)
{
  vector<vector<int> > matrix = {{1,2,2,2,2,5}};
  EXPECT_TRUE(s.searchMatrix(matrix, 2));
}
