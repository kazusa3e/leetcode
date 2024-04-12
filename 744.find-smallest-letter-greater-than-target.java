/*
 * @lc app=leetcode id=744 lang=java
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int minDiff = Integer.MAX_VALUE;
        char letter = 0;
        for (char ch : letters) {
            if (ch <= target) continue;
            int diff = ch - target;
            if (diff < minDiff) {
                minDiff = diff; letter = ch;
            }
        }
        return (minDiff == Integer.MAX_VALUE) ? letters[0] : letter;
    }
}
// @lc code=end
