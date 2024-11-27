/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        // [num_zeros, num_ones] => ans
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (const auto &s : strs) {
            int num_zeros = count(s.begin(), s.end(), '0'),
                num_ones = s.size() - num_zeros;
            
            for (int i = m; i >= num_zeros; --i) {
                for (int j = n; j >= num_ones; --j) {
                    dp[i][j] = max(
                        dp[i][j],
                        dp[i - num_zeros][j - num_ones] + 1
                    );
                }
            }
        }

        return dp.back().back();
    }
};
// @lc code=end
