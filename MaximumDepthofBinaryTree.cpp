/*
 * Given a binary tree, find its maximum depth.
 * Note: The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */
#include "common.h"

class Solution {
public:
    int maxDepth(TreeNode *root) {
      if (root == NULL){
        return 0;
      }
      else{
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
      }
    }
};
Solution s;
TEST(MaximumDepthofBinaryTree, normal)
{
  TreeNode *root = new TreeNode(1);
  TreeNode *left = new TreeNode(1);
  TreeNode *right = new TreeNode(1);
  root->left= left;
  root->right= right;
  root->left->left = new TreeNode(1);
  EXPECT_EQ(3, s.maxDepth(root));
}

TEST(MaximumDepthofBinaryTree, empty)
{
  EXPECT_EQ(0, s.maxDepth(NULL));
}
