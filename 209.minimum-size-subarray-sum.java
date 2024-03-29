/*
 * @lc app=leetcode id=209 lang=java
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start
class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        if (nums.length == 1) {
            return (nums[0] >= target) ? 1 : 0;
        }
        int left = 0;
        int subSum = 0;
        int winSize = Integer.MAX_VALUE;
        for (int right = 0; right != nums.length; ++right) {
            subSum += nums[right];
            while (subSum >= target) {
                winSize = Integer.min(winSize, right - left + 1);
                subSum -= nums[left];
                left += 1;
            }
        }
        return (winSize == Integer.MAX_VALUE) ? 0 : winSize;
    }
}
// @lc code=end
