/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i != dp.size(); ++i) {
            dp[i] = min(
                dp[i - 2] + cost[i - 2],
                dp[i - 1] + cost[i - 1]
            );
        }
        return dp.back();
    }
};
// @lc code=end
