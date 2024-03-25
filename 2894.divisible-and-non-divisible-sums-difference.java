/*
 * @lc app=leetcode id=2894 lang=java
 *
 * [2894] Divisible and Non-divisible Sums Difference
 */

// @lc code=start
class Solution {
    public int differenceOfSums(int n, int m) {
        int num1 = 0;
        int num2 = 0;
        for (int ix = 1; ix <= n; ++ix) {
            if (ix % m == 0) {
                num2 += ix;
            } else {
                num1 += ix;
            }
        }
        return num1 - num2;
    }
}
// @lc code=end
