/*
 * @lc app=leetcode id=485 lang=java
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int cnt = 0;
        int maxCount = 0;
        for (int ix = 0; ix != nums.length; ++ix) {
            if (nums[ix] == 1) {
                cnt += 1;
            } else {
                maxCount = Math.max(maxCount, cnt);
                cnt = 0;
            }
        }
        maxCount = Math.max(maxCount, cnt);
        return maxCount;
    }
}
// @lc code=end
