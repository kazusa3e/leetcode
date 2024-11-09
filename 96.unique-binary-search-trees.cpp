/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(max(n + 1, 3), 0); dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (int ix = 3; ix != max(n + 1, 3); ++ix) {
            for (int l = 0; l != ix; ++l) {
                dp[ix] += (dp[l] * dp[ix - l - 1]);
            }
        }
        return dp[n];
    }
};
// @lc code=end
