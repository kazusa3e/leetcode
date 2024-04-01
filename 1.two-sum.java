/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 */

// @lc code=start

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int ix = 0; ix != nums.length; ++ix) {
            if (map.containsKey(nums[ix])) {
                return new int[] { ix, map.get(nums[ix])
                };
            }
            map.put(target - nums[ix], ix);
        }
        return new int[] { -1, -1 };
    }
}
// @lc code=end
