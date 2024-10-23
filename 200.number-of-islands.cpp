/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int directions[4][2] = {
        {0, 1}, {1, 0}, {0, -1}, {-1, 0},
    };

public:

    void dfs(const vector<vector<char>> &grid, vector<vector<bool>> &&visited, int x, int y) {
        visited[x][y] = true;
        for (const auto &d: directions) {
            int new_x = x + d[0], new_y = y + d[1];
            if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size()) continue;
            if (!visited[new_x][new_y] && grid[new_x][new_y] == '1') {
                dfs(grid, std::move(visited), new_x, new_y);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        unsigned ans = 0;

        for (unsigned i = 0; i != grid.size(); ++i) {
            for (unsigned j = 0; j != grid[0].size(); ++j) {
                if (visited[i][j]) continue;
                if (grid[i][j] == '0') continue;
                ans += 1;
                dfs(grid, std::move(visited), i, j);
            }
        }

        return ans;
    }
};
// @lc code=end
