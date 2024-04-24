/*
 * @lc app=leetcode id=509 lang=java
 *
 * [509] Fibonacci Number
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int fib(int n) {
        List<Integer> table = new ArrayList<>();
        table.add(0);
        table.add(1);
        int idx = 2;
        while (idx <= n) {
            table.add(table.get(idx - 1) + table.get(idx - 2));
            idx += 1;
        }
        return table.get(n);
    }
}
// @lc code=end
