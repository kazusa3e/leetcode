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
        int l = 0;
        long lsum = 0, rsum = Arrays.stream(nums).sum() - nums[0];
        while (l != nums.length && lsum != rsum) {
            lsum += nums[l];
            l += 1;
            if (l != nums.length) {
                rsum -= nums[l];
            }
        }
        if (l == nums.length)
            return -1;
        return (lsum == rsum) ? l : -1;
    }
}
// @lc code=end
