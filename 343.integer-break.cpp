/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1); dp[0] = 0; dp[1] = 0; dp[2] = 1;
        for (int ix = 3; ix <= n; ++ix) {
            for (int j = 2; j != ix; ++j) {
                dp[ix] = max({dp[ix], j * (ix - j), j * dp[ix - j]});
            }
        }
        return dp[n];
    }
};
// @lc code=end
