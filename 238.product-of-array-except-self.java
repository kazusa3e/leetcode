/*
 * @lc app=leetcode id=238 lang=java
 *
 * [238] Product of Array Except Self
 */

// @lc code=start
class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] ret = new int[nums.length];

        for (int ix = nums.length - 1; ix >= 0; --ix) {
            if (ix == nums.length - 1) ret[ix] = nums[ix];
            else ret[ix] = nums[ix] * ret[ix + 1];
        }
        
        for (int ix = 0; ix != nums.length; ++ix) {
            if (ix == 0) nums[ix] = nums[ix];
            else nums[ix] = nums[ix] * nums[ix - 1];
        }

        for (int ix = 0; ix != nums.length; ++ix) {
            if (ix == 0) ret[ix] = ret[ix + 1];
            else if (ix == nums.length - 1) ret[ix] = nums[nums.length - 2];
            else ret[ix] = nums[ix - 1] * ret[ix + 1];
        }
        return ret;
    }
}
// @lc code=end

