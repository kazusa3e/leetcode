/*
 * @lc app=leetcode id=454 lang=java
 *
 * [454] 4Sum II
 */

// @lc code=start

import java.util.HashMap;
import java.util.Map;

class Solution {
    public int fourSumCount(int[] nums1, int[] nums2, int[] nums3, int[] nums4) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i : nums1) {
            for (int j : nums2) {
                int s = i + j;
                map.put(s, map.getOrDefault(s, 0) + 1);
            }
        }
        int cnt = 0;
        for (int i : nums3) {
            for (int j : nums4) {
                int s = i + j;
                cnt += map.getOrDefault(-s, 0);
            }
        }
        return cnt;
    }
}
// @lc code=end
