/*
 * @lc app=leetcode id=26 lang=java
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start
class Solution {
    public int removeDuplicates(int[] nums) {
        int slow = 1, fast = 1;
        while (fast != nums.length) {
            if (nums[fast] != nums[slow - 1]) {
                nums[slow] = nums[fast];
                slow += 1;
            }
            fast += 1;
        }
        return slow;
    }
}
// @lc code=end
