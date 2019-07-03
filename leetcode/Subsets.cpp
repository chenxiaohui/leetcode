/*

Given a set of distinct integers, S, return all possible subsets.
Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.


For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

*/

#include "common.h"

class Solution {
public:
    vector<vector<int>> getSubsets(vector<int> &subset) {
        vector<vector<int>> res;
        vector<int> last;
        res.push_back(last);
        for (size_t i = 0; i < subset.size(); i++) {
            res.push_back(vector<int>(subset[i]));
            size_t size = res.size();
            for (size_t j = 0; j < size; j++) {
                res.push_back(res[j]);
                res.back().push_back(subset[i]);
            }
        }
        return res;
    }

};
Solution s;

TEST(Subsets, normal) {
    vector<int> subset = {1,2,3};
    auto res = s.getSubsets(subset);
    for (auto& vec : res) {
        for (auto& element : vec) {
            cout<< element << " " << endl;
        }
    }
}
