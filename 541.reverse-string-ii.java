/*
 * @lc app=leetcode id=541 lang=java
 *
 * [541] Reverse String II
 */

// @lc code=start
class Solution {
    private static void reverse(char[] chs, int start, int end) {
        for (int l = start, r = end - 1; l < r; ++l, --r) {
            char ch = chs[l];
            chs[l] = chs[r];
            chs[r] = ch;
        }
    }

    public String reverseStr(String s, int k) {
        char[] chs = s.toCharArray();
        for (int ix = 0; ix < s.length(); ix += (k * 2)) {
            reverse(chs, ix, (ix + k >= s.length()) ? s.length() : ix + k);
        }
        return new String(chs);
    }
}
// @lc code=end
