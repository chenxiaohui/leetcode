/*
Write an efficient algorithm that searches for a value in an m x n matrix, return the occurrence of it.This matrix has the following properties:    * Integers in each row are sorted from left to right.    * Integers in each column are sorted from up to bottom.
*/

#include "common.h"

class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        int count = 0;
        if (matrix.size() > 0 && matrix.at(0).size() > 0) {
          int i = matrix.size()  - 1;
          int j = 0;
          while (i >= 0 && j < static_cast<int>(matrix.at(0).size())) {
            if (matrix[i][j] < target) {
              j++;
            } else if (matrix[i][j] > target) {
              i--;
            } else {
              count ++;
              j++;
            }
          }
        }
      return count;
    }
};
Solution s;

TEST(Searcha2DMatrixII, normal) {
  vector<vector<int> > matrix = {
    {1, 3, 5, 7},
    {2, 4, 7, 8},
    {3, 5, 9, 10}
  };
  EXPECT_EQ(2, s.searchMatrix(matrix, 3));
}
TEST(Searcha2DMatrixII, empty)
{
  vector<vector<int> > matrix;
  EXPECT_EQ(0, s.searchMatrix(matrix, 3));
}
TEST(Searcha2DMatrixII, oneline)
{
  vector<vector<int> > matrix = {{1,2,5}};
  EXPECT_EQ(1, s.searchMatrix(matrix, 2));
}
TEST(Searcha2DMatrixII, notfound)
{
  vector<vector<int> > matrix = {
    {1, 3, 5, 7},
    {2, 4, 7, 8},
    {3, 5, 9, 10}
  };
  EXPECT_EQ(0, s.searchMatrix(matrix, 13));
}
