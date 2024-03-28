/*
 * @lc app=leetcode id=1480 lang=java
 *
 * [1480] Running Sum of 1d Array
 */

// @lc code=start
class Solution {
    public int[] runningSum(int[] nums) {
        for (int ix = 1; ix != nums.length; ++ix) {
            nums[ix] += nums[ix - 1];
        }
        return nums;
    }
}
// @lc code=end
