/*
 * @lc app=leetcode id=78 lang=java
 *
 * [78] Subsets
 */

// @lc code=start

import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ret = new ArrayList<>();
        for (int ix = 0; ix != (int) Math.pow(2, nums.length); ++ix) {
            List<Integer> lst = new ArrayList<>();
            for (int i = 0; i != nums.length; ++i) {
                if ((ix & (0x01 << i)) != 0x00) {
                    lst.add(nums[i]);
                }
            }
            ret.add(lst);
        }
        return ret;
    }
}
// @lc code=end
