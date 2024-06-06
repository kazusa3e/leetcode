/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp = {0, 1, 2};
        while (dp.size() < n + 1) {
            int i = dp.size();
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
};
// @lc code=end
