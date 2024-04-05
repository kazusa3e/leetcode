/*
 * @lc app=leetcode id=1047 lang=java
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

// @lc code=start
class Solution {
    public String removeDuplicates(String s) {
        char[] chs = s.toCharArray();
        int w = 0;
        for (int r = 0; r != chs.length; ++r) {
            chs[w] = chs[r];
            if (w > 0 && chs[w] == chs[w - 1]) {
                w -= 1;
            } else {
                w += 1;
            }
        }
        return new String(chs, 0, w);
    }
}
// @lc code=end
