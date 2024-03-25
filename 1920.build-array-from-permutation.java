/*
 * @lc app=leetcode id=1920 lang=java
 *
 * [1920] Build Array from Permutation
 */

// @lc code=start
class Solution {
    public int[] buildArray(int[] nums) {
        final int mask = 0x03ff;
        for (int ix = 0; ix != nums.length; ++ix) {
            nums[ix] = nums[ix] | ((nums[nums[ix]] & mask) << 10);
        }
        for (int ix = 0; ix != nums.length; ++ix) {
            nums[ix] = (nums[ix] & (~mask)) >> 10;
        }
        return nums;
    }
}
// @lc code=end
