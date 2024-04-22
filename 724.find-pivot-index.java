/*
 * @lc app=leetcode id=724 lang=java
 *
 * [724] Find Pivot Index
 */

// @lc code=start

import java.util.Arrays;

class Solution {
    public int pivotIndex(int[] nums) {
        if (nums.length == 1) {
            return 0;
        }
        int sum = Arrays.stream(nums).sum();
        int acc = 0;
        int ix = 0;
        while (ix != nums.length) {
            if (acc * 2 + nums[ix] == sum) break;
            acc += nums[ix++];
        }
        return (ix == nums.length) ? -1 : ix;
    }
}
// @lc code=end
