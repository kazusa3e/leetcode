/*
 * @lc app=leetcode id=1512 lang=java
 *
 * [1512] Number of Good Pairs
 */

// @lc code=start

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int numIdenticalPairs(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int n : nums) {
            map.put(n, map.getOrDefault(n, 0) + 1);
        }
        int ret = 0;
        for (Map.Entry<Integer, Integer> e : map.entrySet()) {
            int times = e.getValue();
            if (times > 1) {
                ret += (times * (times - 1) / 2);
            }
        }
        return ret;
    }
}
// @lc code=end
