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

        vector<int> dp(caps + 1, 0); dp[0] = 1;

        for (int i = 0; i != nums.size(); ++i) {
            for (int j = caps; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp.back();
    }
};
// @lc code=end
