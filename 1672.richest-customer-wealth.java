/*
 * @lc app=leetcode id=1672 lang=java
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public int maximumWealth(int[][] accounts) {
        int max = 0;
        for (int[] customer : accounts) {
            int wealth = Arrays.stream(customer).sum();
            if (wealth > max) {
                max = wealth;
            }
        }
        return max;
    }
}
// @lc code=end
