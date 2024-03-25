/*
 * @lc app=leetcode id=35 lang=java
 *
 * [35] Search Insert Position
 */

// @lc code=start
class Solution {
    public int searchInsert(int[] nums, int target) {
        int left = 0, right = nums.length;
        int mid = left + ((right - left) >> 1);
        while (left < right) {
            if (target < nums[mid]) {
                right = mid;
            } else if (target > nums[mid]) {
                left = mid + 1;
            } else {
                break;
            }
            mid = left + ((right - left) >> 1);
        }
        return mid;
    }
}
// @lc code=end
