/*
 * @lc app=leetcode id=448 lang=java
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ret = new ArrayList<>();
        for (int ix = 0; ix != nums.length; ++ix) {
            int idx = Math.abs(nums[ix]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }
        for (int ix = 0; ix != nums.length; ++ix) {
            if (nums[ix] > 0) ret.add(ix + 1);
        }
        return ret;
    }
}
// @lc code=end

