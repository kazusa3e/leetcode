/*
 * @lc app=leetcode id=977 lang=java
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start
class Solution {
    public int[] sortedSquares(int[] nums) {
        if (nums.length == 1) {
            return new int[] { nums[0] * nums[0] };
        }
        int[] ret = new int[nums.length];
        int idx = nums.length - 1;
        int left = 0, right = nums.length - 1;
        while (left <= right) {
            if (Math.abs(nums[left]) > Math.abs(nums[right])) {
                ret[idx--] = nums[left] * nums[left];
                left += 1;
            } else {
                ret[idx--] = nums[right] * nums[right];
                right -= 1;
            }
        }
        return ret;
    }
}
// @lc code=end
