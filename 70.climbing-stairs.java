/*
 * @lc app=leetcode id=70 lang=java
 *
 * [70] Climbing Stairs
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public int climbStairs(int n) {
        List<Integer> dp = new ArrayList<>();
        dp.add(-1);
        dp.add(1);
        dp.add(2);
        for (int ix = 3; ix <= n; ++ix) {
            dp.add(dp.get(ix - 1) + dp.get(ix - 2));
        }
        return dp.get(n);
    }

}
// @lc code=end
