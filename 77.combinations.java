/*
 * @lc app=leetcode id=77 lang=java
 *
 * [77] Combinations
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<List<Integer>> result;
    private List<Integer> path;
    private void backtracking(int n, int k, int startIndex) {
        if (path.size() == k) {
            result.add(new ArrayList<>(path));
            return;
        }
        for (int i = startIndex; i <= n - (k - path.size()) + 1; ++i) {
            path.add(i);
            backtracking(n, k, i + 1);
            path.removeLast();
        }
    }
    public List<List<Integer>> combine(int n, int k) {
        result = new ArrayList<>();
        path = new ArrayList<>();
        backtracking(n, k, 1);
        return result;
    }
}
// @lc code=end

