#include "common.h"
using namespace std;

namespace four_sum {

class Solution {
public:

    vector<vector<int> > three_sum(vector<int>& nums, int target) {
        vector<vector<int> > results;
        for (int i = 0; i < int(nums.size())-2; i++) {
            if (i > 0 && nums[i]==nums[i-1]) continue;
            int first = nums[i];
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                if (first+nums[j]+nums[k]==target) {
                    vector<int> result = {first, nums[j], nums[k]};
                    results.push_back(result);
                    ++j; --k;
                }
                else if (first+nums[j]+nums[k]>target) --k;
                else if (first+nums[j]+nums[k]<target) ++j;
            }
        }
        return results;
    }

    vector<vector<int> > four_sum(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int> > results;
        for (unsigned int i = 0; i < nums.size(); i++) {
            if (i>0 && nums[i]==nums[i-1]) continue;
            std::vector<int> remain; remain.assign(nums.begin()+i+1, nums.end());
            vector<vector<int> > three_sumResults = three_sum(remain, target-nums[i]);
            for (unsigned int j = 0; j < three_sumResults.size(); j++) {
                vector<int> result(three_sumResults[j]);
                result.insert(result.begin(), nums[i]);
                results.push_back(result);
            }
        }
        return results;
    }

    void test_case1() {
        vector<int> nums = {-1,0,-5,-2,-2,-4,0,1,-2};
        vector<vector<int> > results = four_sum(nums, -9);
        std::cout << "++++RESULTS+++" << std::endl;
        for (unsigned int i = 0; i < results.size(); i++) {
            std::cout << results[i][0] << " " << results[i][1] << " " << results[i][2] << " " << results[i][3] << std::endl;
        }
    }
};

}
