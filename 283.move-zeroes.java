/*
 * @lc app=leetcode id=283 lang=java
 *
 * [283] Move Zeroes
 */

// @lc code=start
class Solution {
    public void moveZeroes(int[] nums) {
        int left = 0, right = 0;
        while (right != nums.length) {
            if (nums[right] != 0) {
                nums[left++] = nums[right];
            }
            right += 1;
        }
        while (left != nums.length) {
            nums[left++] = 0;
        }
    }
}
// @lc code=end
