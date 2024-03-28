/*
 * @lc app=leetcode id=1365 lang=java
 *
 * [1365] How Many Numbers Are Smaller Than the Current Number
 */

// @lc code=start
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int[] times = new int[101];
        for (int ix = 0; ix != nums.length; ++ix) {
            times[nums[ix]] += 1;
        }
        for (int ix = 1; ix != times.length; ++ix) {
            times[ix] += times[ix - 1];
        }
        int[] ret = new int[nums.length];
        for (int ix = 0; ix != ret.length; ++ix) {
            ret[ix] = (nums[ix] == 0) ? 0 : times[nums[ix] - 1];
        }
        return ret;
    }
}
// @lc code=end
