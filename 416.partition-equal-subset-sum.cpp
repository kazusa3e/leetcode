/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, 0));
        for (unsigned i = 0; i != nums.size(); ++i) dp[i][0] = 0;
        for (unsigned j = 0; j <= sum / 2; ++j) dp[0][j] = (j >= nums[0]) ? nums[0] : 0;
        for (unsigned i = 1; i != nums.size(); ++i) {
            for (unsigned j = 1; j <= sum / 2; ++j) {
                if (j < nums[i]) dp[i][j] = dp[i - 1][j];
                else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
            }
        }
        return dp.back().back() == (double) sum / 2;
    }
};
// @lc code=end
