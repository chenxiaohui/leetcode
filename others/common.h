#include <iostream>
#include <iterator>
#include <algorithm>
#include <stack>
#include <gtest/gtest.h>
#include <stdarg.h>
#include <stdio.h>

using namespace std;
#define n(A) sizeof(A)/sizeof(int)

void print(const vector<int>& ve){
   cout << "[";
   copy(ve.begin(), ve.end(), ostream_iterator<int>(cout, ","));
   //for (vector<int>::const_iterator it = ve.begin(); it != ve.end(); it++){
     //cout << *it << ",";
   //}
   cout <<"]" <<endl;
}
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
