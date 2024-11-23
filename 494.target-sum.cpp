/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start

#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > sum) return 0;
        if ((sum + target) % 2 == 1) return 0;
        const int caps = (sum + target) / 2;

        // [item, caps] => num_methods
        vector<vector<unsigned>> dp(nums.size(), vector<unsigned>(caps + 1, 0));

        dp[0][0] = 1;
        if (nums[0] <= caps) dp[0][nums[0]] = 1;
        unsigned num_zeros = 0;
        for (unsigned i = 0; i != nums.size(); ++i) {
            if (nums[i] == 0) num_zeros += 1;
            dp[i][0] = pow(2, num_zeros);
        }

        for (unsigned i = 1; i != nums.size(); ++i) {
            for (unsigned j = 0; j != caps + 1; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= nums[i]) {
                    dp[i][j] += dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end
