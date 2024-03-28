/*
 * @lc app=leetcode id=2824 lang=java
 *
 * [2824] Count Pairs Whose Sum is Less than Target
 */

// @lc code=start

import java.util.Collections;
import java.util.List;

class Solution {
    public int countPairs(List<Integer> nums, int target) {
        if (nums.size() == 1) {
            return 0;
        }
        Collections.sort(nums);
        int left = 0;
        int cnt = 0;
        while (left != nums.size() - 1) {
            int right = left + 1;
            while (right != nums.size() && nums.get(left) + nums.get(right) < target) {
                cnt += 1;
                right += 1;
            }
            left += 1;
        }
        return cnt;
    }
}
// @lc code=end
