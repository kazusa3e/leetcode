/*
 * @lc app=leetcode id=797 lang=java
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    private List<List<Integer>> results;
    private List<Integer> path;
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        results = new ArrayList<>();
        path = new ArrayList<>();
        path.add(0);
        backtracking(graph, 0);
        return results;
    }
    private void backtracking(int[][] graph, int current) {
        if (path.get(path.size() - 1) == graph.length - 1) {
            results.add(new ArrayList<>(path));
            return;
        }
        if (path.size() == graph.length) return;
        for (int n : graph[current]) {
            path.add(n);
            backtracking(graph, n);
            path.removeLast();
        }
    }
}
// @lc code=end

