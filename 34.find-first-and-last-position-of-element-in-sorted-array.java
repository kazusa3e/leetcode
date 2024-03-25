/*
 * @lc app=leetcode id=34 lang=java
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

// @lc code=start
class Solution {
    public int[] searchRange(int[] nums, int target) {
        if (nums.length == 0) {
            return new int[] { -1, -1 };
        }
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
        if (mid >= nums.length) {
            return new int[] { -1, -1 };
        }
        if (nums[mid] != target) {
            return new int[] { -1, -1 };
        }
        left = right = mid;
        while (left > 0 && nums[left - 1] == target) {
            left -= 1;
        }
        while (right < nums.length - 1 && nums[right + 1] == target) {
            right += 1;
        }
        return new int[] { left, right };
    }
}
// @lc code=end
