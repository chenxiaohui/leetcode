/*
 *  find a subset of a sequence which sum equals a given value(or near the value)
 */
#include "common.h"
#include <math.h>

class Solution {
  public:
    int findSolution(const int target, const vector<int>& input, const size_t pos, vector<int>& output) {
      int ret = 0;
      if (!input.empty() && pos < input.size() && target > 0) {
        int minBias = target;
        int minPos = -1;
        for (size_t i = pos; i < input.size(); i++) {
          int sub = findSolution(target - input[i], input, i + 1, output);
          int bias = abs(target - input[i] - sub);
          if (bias < minBias) {
            minBias = bias;
            ret = sub + input[i];
            minPos = i;
          }
        }
      }
      return ret;
    }
};

Solution s;
TEST(SequenceSumReachValue, normal) {
  vector<int> input = {1,3,5,6,7};
  int target  = 10;
  vector<int> output;
  cout<<s.findSolution(target, input, 0, output);
  //print(output);
}
TEST(SequenceSumReachValue, near) {
  vector<int> input = {2,5,6,9};
  int target  = 10;
  vector<int> output;
  cout<<s.findSolution(target, input, 0, output);
  //print(output);
}

TEST(SequenceSumReachValue, below) {
  vector<int> input = {1,1,1,1};
  int target  = 10;
  vector<int> output;
  cout<<s.findSolution(target, input, 0, output);
  //print(output);
}
TEST(SequenceSumReachValue, over) {
  vector<int> input = {12,11,111,11111};
  int target  = 10;
  vector<int> output;
  cout<<s.findSolution(target, input, 0, output);
  //print(output);
}
