/*
 * @lc app=leetcode id=88 lang=java
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = 0, j = 0;
        int[] tmp = new int[m + n];
        int idx = 0;
        while (i != m && j != n) {
            if (nums1[i] < nums2[j]) {
                tmp[idx++] = nums1[i++];
            } else {
                tmp[idx++] = nums2[j++];
            }
        }
        while (i != m) {
            tmp[idx++] = nums1[i++];
        }
        while (j != n) {
            tmp[idx++] = nums2[j++];
        }
        for (int ix = 0; ix != nums1.length; ++ix) {
            nums1[ix] = tmp[ix];
        }
    }
}
// @lc code=end

