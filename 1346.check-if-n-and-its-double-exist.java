/*
 * @lc app=leetcode id=1346 lang=java
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start

import java.util.HashSet;
import java.util.Set;

class Solution {
    public boolean checkIfExist(int[] arr) {
        Set<Integer> set = new HashSet<>();
        for (int n : arr) {
            if (set.contains(n)) return true;
            set.add(n * 2);
            if (n % 2 == 0) set.add(n / 2);
        }
        return false;
    }
}
// @lc code=end

