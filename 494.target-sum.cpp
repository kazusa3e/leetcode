/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start

#include <vector>
#include <numeric>

using namespace std;

class Solution {
private:
    vector<int> nums_;
    int target_;
    int num_methods {0};
    int subsum {0};
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        nums_ = nums;
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 == 1) return 0;
        target_ = (sum + target) / 2;

        backtracking(nums_.begin());
        return num_methods;
    }

    void backtracking(vector<int>::iterator begin) {
        if (subsum == target_) num_methods += 1;
        for (auto iter = begin; iter != nums_.end(); ++iter) {
            subsum += *iter;
            backtracking(iter + 1);
            subsum -= *iter;
        }
    }
};
// @lc code=end
