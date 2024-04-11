/*
 * @lc app=leetcode id=448 lang=java
 *
 * [448] Find All Numbers Disappeared in an Array
 */

// @lc code=start

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ret = new ArrayList<>();
        Arrays.sort(nums);
        for (int i = 1; i != nums[0]; ++i) {
            ret.add(i);
        }
        for (int ix = 1; ix != nums.length; ++ix) {
            if (nums[ix] - nums[ix - 1] > 1) {
                for (int i = nums[ix - 1] + 1; i != nums[ix]; ++i) {
                    ret.add(i);
                }
            }
        }
        for (int i = nums[nums.length - 1] + 1; i <= nums.length; ++i) {
            ret.add(i);
        }
        return ret;
    }
}
// @lc code=end

