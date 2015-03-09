#include <iostream>
#include <iterator>
#include <algorithm>
#include <stack>
#include <gtest/gtest.h>
using namespace std;
#define n(A) sizeof(A)/sizeof(int)
/**
 * Definition for binary tree
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
