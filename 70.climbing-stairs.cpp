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
        vector<int> dp(max(n + 1, 3), 0);
        dp[0] = -1; dp[1] = 1; dp[2] = 2;
        if (n < 3) return dp[n];
        for (int ix = 3; ix <= n; ++ix) {
            dp[ix] = dp[ix - 1] + dp[ix - 2];
        }
        return dp[n];
    }
};
// @lc code=end
