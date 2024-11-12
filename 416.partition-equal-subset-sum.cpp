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
        vector<unsigned> dp(sum / 2 + 1, 0);
        for (unsigned j = 0; j <= sum / 2; ++j) dp[j] = (j >= nums[0]) ? nums[0] : 0;
        for (unsigned i = 1; i != nums.size(); ++i) {
            for (unsigned j = sum / 2; j >= nums[i]; --j) {
                if (j < nums[i]) dp[j] = dp[j];
                else dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        return dp.back() == (double) sum / 2;
    }
};
// @lc code=end
