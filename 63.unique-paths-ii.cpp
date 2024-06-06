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
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i][j - 1];
                } else if (j == 0) {
                    dp[i][j] = (obstacleGrid[i][j] == 1) ? 0 : dp[i - 1][j];
                } else {
                    if (obstacleGrid[i][j] == 1) {
                        dp[i][j] = 0;
                        continue;
                    }
                    int l = (obstacleGrid[i - 1][j] == 1) ? 0 : dp[i - 1][j];
                    int u = (obstacleGrid[i][j - 1] == 1) ? 0 : dp[i][j - 1];
                    dp[i][j] = l + u;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end
