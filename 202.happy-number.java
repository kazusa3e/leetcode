/*
 * @lc app=leetcode id=202 lang=java
 *
 * [202] Happy Number
 */

// @lc code=start

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Solution {

    private static int next(int n) {
        List<Integer> nums = new ArrayList<>();
        while (n != 0) {
            nums.add(n % 10);
            n /= 10;
        }
        return nums.stream().mapToInt(x -> x * x).sum();
    }

    public boolean isHappy(int n) {
        Set<Integer> records = new HashSet<>();
        while (!records.contains(n)) {
            records.add(n);
            if (n == 1) {
                return true;
            }
            n = next(n);
        }
        return false;
    }
}
// @lc code=end
