#include "common.h"
/**
 * Definition for binary tree
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (p == NULL || q == NULL) {
          return p == q;
        }
        else {
          return p->val == q->val && isSameTree(p->left, q->left)
            && isSameTree(p->right, q->right);
        }
    }
} s;

TEST(SameTree, TestNUll)
{
  TreeNode * p = new TreeNode(1);
  EXPECT_EQ(true, s.isSameTree(NULL, NULL));
  EXPECT_EQ(false, s.isSameTree(NULL, p));
  EXPECT_EQ(false, s.isSameTree(p, NULL));
  delete p;
}

TEST(SameTree, TestNormal)
{
  TreeNode * p = new TreeNode(1);
  TreeNode * q = new TreeNode(1);
  p->left = new TreeNode(2);
  q->left = new TreeNode(2);
  q->left->left = new TreeNode(2);
  p->left->left = new TreeNode(2);
  EXPECT_EQ(true, s.isSameTree(p, q));
}
