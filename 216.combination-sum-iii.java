/*
 * @lc app=leetcode id=216 lang=java
 *
 * [216] Combination Sum III
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<Integer> path;
    private List<List<Integer>> result;
    public List<List<Integer>> combinationSum3(int k, int n) {
        path = new ArrayList<>();
        result = new ArrayList<>();
        backtracking(k, n, 1);
        return result;
    }
    private void backtracking(int k, int n, int startIndex) {
        if (path.size() == k) {
            if (path.stream().mapToInt(x -> x).sum() == n) {
                result.add(new ArrayList<>(path));
            }
            return;
        }
        if (startIndex + (k - path.size()) > 10) return;
        for (int i = startIndex; i != 10; ++i) {
            path.add(i);
            backtracking(k, n, i + 1);
            path.removeLast();
        }
    }
}
// @lc code=end
