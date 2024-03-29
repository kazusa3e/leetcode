/*
 * @lc app=leetcode id=904 lang=java
 *
 * [904] Fruit Into Baskets
 */

// @lc code=start

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int totalFruit(int[] fruits) {
        Map<Integer, Integer> map = new HashMap<>();
        int ret = 0;
        for (int left = 0, right = 0; right != fruits.length; ++right) {
            map.put(fruits[right], map.getOrDefault(fruits[right], 0) + 1);
            while (map.size() > 2) {
                map.put(fruits[left], map.get(fruits[left]) - 1);
                map.remove(fruits[left], 0);
                left += 1;
            }
            ret = Math.max(ret, right - left + 1);
        }
        return ret;
    }
}
// @lc code=end
