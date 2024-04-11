/*
 * @lc app=leetcode id=39 lang=java
 *
 * [39] Combination Sum
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {
    private List<Integer> combie;
    private Set<List<Integer>> results;
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        combie = new ArrayList<>();
        results = new HashSet<>();
        backtracking(candidates, target);
        return new ArrayList<>(results);
    }
    private void backtracking(int[] candidates, int target) {
        int sum = combie.stream().mapToInt(x -> x).sum();
        if (sum > target) return;
        if (sum == target) {
            List<Integer> tmp = new ArrayList<>(combie);
            Collections.sort(tmp);
            results.add(new ArrayList<>(tmp));
            return;
        }
        for (int n : candidates) {
            combie.add(n);
            backtracking(candidates, target);
            combie.removeLast();
        }
    }
}
// @lc code=end

