/*
 * @lc app=leetcode id=561 lang=java
 *
 * [561] Array Partition
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public int arrayPairSum(int[] nums) {
        Arrays.sort(nums);
        int ret = 0;
        for (int ix = 0; ix != nums.length; ix += 2) {
            ret += nums[ix];
        }
        return ret;
    }
}
// @lc code=end
