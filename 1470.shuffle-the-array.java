/*
 * @lc app=leetcode id=1470 lang=java
 *
 * [1470] Shuffle the Array
 */

// @lc code=start
class Solution {
    public int[] shuffle(int[] nums, int n) {
        final int mask = 0x03ff;
        for (int ix = 0; ix != n; ++ix) {
            nums[ix * 2] = nums[ix * 2] | ((nums[ix] & mask) << 10);
            nums[ix * 2 + 1] = nums[ix * 2 + 1] | ((nums[ix + n] & mask) << 10);
        }
        for (int ix = 0; ix != nums.length; ++ix) {
            nums[ix] = (nums[ix] >> 10) & mask;
        }
        return nums;
    }
}
// @lc code=end
