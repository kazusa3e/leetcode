/*
 * @lc app=leetcode id=268 lang=java
 *
 * [268] Missing Number
 */

// @lc code=start
class Solution {
    public int missingNumber(int[] nums) {
        long sum = nums.length * (nums.length + 1) / 2;
        for (int n : nums) {
            sum -= n;
        }
        return (int) sum;
    }
}
// @lc code=end
