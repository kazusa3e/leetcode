/*
 * @lc app=leetcode id=1929 lang=java
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
class Solution {
    public int[] getConcatenation(int[] nums) {
        int[] ret = new int[nums.length * 2];
        for (int ix = 0; ix != nums.length; ++ix) {
            ret[ix] = nums[ix];
            ret[ix + nums.length] = nums[ix];
        }
        return ret;
    }
}
// @lc code=end
