/*
 * @lc app=leetcode id=344 lang=java
 *
 * [344] Reverse String
 */

// @lc code=start
class Solution {
    public void reverseString(char[] s) {
        for (int left = 0, right = s.length - 1; left < right; ++left, --right) {
            char ch = s[left];
            s[left] = s[right];
            s[right] = ch;
        }
    }
}
// @lc code=end
