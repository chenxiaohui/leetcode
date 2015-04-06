/*
 *  Given a list of numbers, return all possible permutations.
 * Note: For nums [1,2,3], the permutaions are: [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]
 */
#include "common.h"

class Solution {
public:
    typedef vector<vector<int> > vector2D;
    vector<vector<int> > permute(vector<int> nums) {
        vector2D output;
        if (nums.size() > 0) {
            vector<int> temp;
            sort(nums.begin(), nums.end());
            permuteHelper(output, temp, nums);
        }
        return output;
    }
    void permuteHelper(vector2D & output, vector<int>& temp,
            vector<int>& elements) {
        if (elements.empty()) {
            output.push_back(temp);
        }
        for (vector<int>::iterator i = elements.begin(); i != elements.end(); i++) {
            if (i > elements.begin() && *i == *(i - 1)) {
                continue;
            }
            temp.push_back(*i);
            int current = *i;
            elements.erase(i);
            permuteHelper(output, temp, elements);
            elements.insert(i, current);
            temp.pop_back();
        }
    }
};
Solution s;
TEST(UniqueSubsets, testnormal)
{
    int elementsArr[] = {1,2,2,2};
    vector<int> elements(elementsArr, elementsArr + sizeof(elementsArr)/sizeof(int));
    vector<vector<int> > outVector = s.permute(elements);
    for(vector<vector<int> >::iterator it = outVector.begin(); it != outVector.end(); it++){
        cout<<"[";
        for (vector<int>::iterator i = it->begin(); i != it->end(); i ++) {
            cout << *i << ",";
        }
        cout<<"]"<<endl;
    }
}

