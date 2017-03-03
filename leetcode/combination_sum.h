#include "common.h"
using namespace std;

namespace combination_sum {

class Solution {
public:

    void combination_sum_helper(vector<int>& candidates, int target, vector<int> &result, vector<vector<int>> &results) {
        if (target < 0) return;
        else if (target == 0) {
            results.push_back(result);
            return;
        }

        for (size_t idx = 0; idx < candidates.size(); ++idx) {
            result.push_back(candidates[idx]);
            combination_sum_helper(candidates, target - candidates[idx], result, results);
            result.pop_back();
        }
    }

    vector<vector<int>> combination_sum(vector<int>& candidates, int target) {
        vector<int> result;
        vector<vector<int>> results;
        combination_sum_helper(candidates, target ,result, results);
        return results;
    }


    void test_case1() {
        vector<int> candidates = {2,3,6,7};
        int target = 7;
        vector<vector<int>> results = combination_sum(candidates, target);
    }
};

}
