/*
 * @lc app=leetcode id=771 lang=java
 *
 * [771] Jewels and Stones
 */

// @lc code=start

import java.util.HashSet;
import java.util.Set;

class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        Set<Character> set = new HashSet<>();
        for (char ch : jewels.toCharArray()) {
            set.add(ch);
        }
        int ret = 0;
        for (char ch : stones.toCharArray()) {
            if (set.contains(ch)) {
                ret += 1;
            }
        }
        return ret;
    }
}
// @lc code=end
