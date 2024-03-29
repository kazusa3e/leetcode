/*
 * @lc app=leetcode id=844 lang=java
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
    public boolean backspaceCompare(String s, String t) {
        char[] schars = s.toCharArray(), tchars = t.toCharArray();
        int ss = 0, sf = 0;
        while (sf != s.length()) {
            if (schars[sf] != '#') {
                schars[ss++] = schars[sf];
            } else {
                if (ss != 0) {
                    ss -= 1;
                }
            }
            sf += 1;
        }
        int ts = 0, tf = 0;
        while (tf != t.length()) {
            if (tchars[tf] != '#') {
                tchars[ts++] = tchars[tf];
            } else {
                if (ts != 0) {
                    ts -= 1;
                }
            }
            tf += 1;
        }
        if (ss != ts) {
            return false;
        }
        ss -= 1;
        ts -= 1;
        while (ss >= 0) {
            if (schars[ss] != tchars[ts]) {
                return false;
            }
            ss -= 1;
            ts -= 1;
        }
        return true;
    }
}
// @lc code=end
