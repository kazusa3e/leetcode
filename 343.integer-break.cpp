/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(59);
        dp[1] = 1;
        for (int i = 2; i <= 58; ++i) {
            int m_max = 0;
            for (int j = 1; j != i; ++j) {
                m_max = max(m_max, max(j * (i - j), j * dp[i - j]));
                dp[i] = m_max;
            }
        }
        return dp[n];
    }
};
// @lc code=end
