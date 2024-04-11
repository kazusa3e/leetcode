/*
 * @lc app=leetcode id=414 lang=java
 *
 * [414] Third Maximum Number
 */

// @lc code=start

import java.util.Iterator;
import java.util.Set;
import java.util.TreeSet;

class Solution {
    public int thirdMax(int[] nums) {
        Set<Integer> set = new TreeSet<>((a, b) -> Integer.compare(b, a));
        for (int n : nums) set.add(n);
        Iterator<Integer> iter = set.iterator();
        if (set.size() >= 3) {
            for (int ix = 0; ix != 2; ++ix) {
                iter.next();
            }
        }
        return iter.next();
    }
}
// @lc code=end

