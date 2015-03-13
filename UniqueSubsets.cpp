/*
 *  Given a list of numbers that may has duplicate numbers, return all possible subsets Note Each element in a subset must be in non-descending order. The ordering between two subsets is free. The solution set must not contain duplicate subsets.
 * Note: Example If S = [1,2,2], a solution is: [ [2], [1], [1,2,2], [2,2], [1,2], [] ]V
 */
#include "common.h"
class Solution {
public:
    vector<vector<int> > subsetsWithDup(const vector<int> &S) {
        // write your code here
        vector<vector<int> > outVector;
        vector<int> elements(S.begin(), S.end());
        sort(elements.begin(), elements.end());
        if (!S.empty()) {
            vector<int> subset;
            subsetsHelper(outVector, subset, S, 0);
        }
        return outVector;
    }
   void subsetsHelper(vector<vector<int> >& outVector, vector<int>& subset, const vector<int>& elements, size_t pos) {
       outVector.push_back(subset);
       for (size_t i = pos; i < elements.size(); i++){
           if (i > 0 && i != pos && elements[i] == elements[i - 1]) {
               continue;
           }
           subset.push_back(elements[i]);
           subsetsHelper(outVector, subset, elements, i + 1);
           subset.pop_back();
       }
   }
};
Solution s;
TEST(UniqueSubsets, )
{
    int elementsArr[] = {4,4,1,4};
    vector<int> elements(elementsArr, elementsArr + sizeof(elementsArr)/sizeof(int));
    vector<vector<int> > outVector = s.subsetsWithDup(elements);
    for(vector<vector<int> >::iterator it = outVector.begin(); it != outVector.end(); it++){
        cout<<"[";
        for (vector<int>::iterator i = it->begin(); i != it->end(); i ++) {
            cout << *i << ",";
        }
        cout<<"]"<<endl;
    }
}

