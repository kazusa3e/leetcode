/*
 * @lc app=leetcode id=1342 lang=java
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
    public int numberOfSteps(int num) {
        int steps = 0;
        while (num != 0) {
            steps += 1;
            num = (num % 2 == 0) ? num / 2 : num - 1;
        }
        return steps;
    }
}
// @lc code=end

