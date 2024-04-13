/*
 * @lc app=leetcode id=200 lang=java
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
    private static final int[][] DIRECTIONS = { {0, 1}, {1, 0}, {-1, 0}, {0, -1}, };
    private void dfs(char[][] grid, boolean[][] visited, int i, int j) {
        int n = grid.length, m = grid[0].length;
        if (i < 0 || i >= n || j < 0 || j >= m) return;
        grid[i][j] = '0';
        visited[i][j] = true;
        for (int[] d : DIRECTIONS) {
            int _i = i + d[0], _j = j + d[1];
            if (_i < 0 || _i >= n || _j < 0 || _j >= m) continue;
            if (grid[_i][_j] == '0') continue;
            if (!visited[_i][_j]) dfs(grid, visited, _i, _j);
        }
    }

    public int numIslands(char[][] grid) {
        int n = grid.length, m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        int cnt = 0;
        for (int i = 0; i != n; ++i) {
            for (int j = 0; j != m; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, visited, i, j);
                    cnt += 1;
                }
            }
        }
        return cnt;
    }
}
// @lc code=end
