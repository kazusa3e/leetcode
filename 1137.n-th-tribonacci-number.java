/*
 * @lc app=leetcode id=1137 lang=java
 *
 * [1137] N-th Tribonacci Number
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int tribonacci(int n) {
        List<Integer> table = new ArrayList<>(List.of(0, 1, 1));
        while (n >= table.size()) {
            table.add(
                    table.get(table.size() - 1)
                            + table.get(table.size() - 2)
                            + table.get(table.size() - 3));
        }
        return table.get(n);
    }
}
// @lc code=end
