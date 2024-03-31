/*
 * @lc app=leetcode id=905 lang=java
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
class Solution {
    public int[] sortArrayByParity(int[] nums) {
        if (nums.length == 1) {
            return nums;
        }
        int left = 0, right = nums.length - 1;
        while (left < right) {
            while (left < right && nums[left] % 2 == 0) {
                left += 1;
            }
            while (left < right && nums[right] % 2 == 1) {
                right -= 1;
            }
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left += 1;
            right -= 1;
        }
        return nums;
    }
}
// @lc code=end
