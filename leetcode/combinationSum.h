#ifndef COMBINATION_SUM_H
#define COMBINATION_SUM_H

#include "CommonDataStructure.h"
using namespace std;

class Solution {
public:

    void combinationSumHelper(vector<int>& candidates, int target, vector<int> &result, vector<vector<int>> &results) {
        if (target < 0) return;
        else if (target == 0) {
            results.push_back(result);
            return;
        }

        for (size_t idx = 0; idx < candidates.size(); ++idx) {
            result.push_back(candidates[idx]);
            combinationSumHelper(candidates, target - candidates[idx], result, results);
            result.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> result;
        vector<vector<int>> results;
        combinationSumHelper(candidates, target ,result, results);
        return results;
    }


    void test_case1() {
        vector<int> candidates = {2,3,6,7};
        int target = 7;
        vector<vector<int>> results = combinationSum(candidates, target);
        int ep = 0;
    }
};

#endif
