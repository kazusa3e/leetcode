/*
 * @lc app=leetcode id=27 lang=java
 *
 * [27] Remove Element
 */

// @lc code=start
class Solution {
    public int removeElement(int[] nums, int val) {
        if (nums.length == 0) {
            return 0;
        }
        if (nums.length == 1) {
            return (nums[0] == val) ? 0 : 1;
        }
        int fast = 0, slow = 0;
        while (fast != nums.length) {
            if (nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
            fast += 1;
        }
        return slow;
    }
}
// @lc code=end
