/*
 * @lc app=leetcode id=2011 lang=java
 *
 * [2011] Final Value of Variable After Performing Operations
 */

// @lc code=start
class Solution {
    public int finalValueAfterOperations(String[] operations) {
        int ret = 0;
        for (String oper : operations) {
            if (oper.equals("--X") || oper.equals("X--")) {
                ret -= 1;
            }
            if (oper.equals("++X") || oper.equals("X++")) {
                ret += 1;
            }
        }
        return ret;
    }
}
// @lc code=end
