/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<unsigned>> dp(m, vector<unsigned>(n, 0)); dp[0][0] = 1;
        for (unsigned i = 0; i != m; ++i) {
            for (unsigned j = 0; j != n; ++j) {
                if (i == 0 && j == 0) continue;
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0; continue;
                }
                unsigned u = (i == 0) ? 0 :
                    ((obstacleGrid[i - 1][j] == 1) ? 0 : dp[i - 1][j]);
                unsigned l = (j == 0) ? 0 :
                    ((obstacleGrid[i][j - 1] == 1) ? 0 : dp[i][j - 1]);
                dp[i][j] = u + l;
            }
        }
        return dp.back().back();
    }
};
// @lc code=end
