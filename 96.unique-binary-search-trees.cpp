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
        vector<int> dp(20);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= 19; ++i) {
            for (int j = 0; j != i; ++j) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
// @lc code=end
