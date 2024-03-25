/*
 * @lc app=leetcode id=442 lang=java
 *
 * [442] Find All Duplicates in an Array
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findDuplicates(int[] nums) {
        List<Integer> ret = new ArrayList<>();
        for (int ix = 0; ix != nums.length; ++ix) {
            int key = Math.abs(nums[ix]) - 1;
            if (nums[key] < 0) {
                ret.add(key + 1);
            }
            nums[key] = -nums[key];
        }
        return ret;
    }
}
// @lc code=end
