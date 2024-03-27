/*
 * @lc app=leetcode id=2798 lang=java
 *
 * [2798] Number of Employees Who Met the Target
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        return (int) Arrays.stream(hours).filter(x -> x >= target).count();
    }
}
// @lc code=end
