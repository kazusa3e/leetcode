/*
 * @lc app=leetcode id=1678 lang=java
 *
 * [1678] Goal Parser Interpretation
 */

// @lc code=start
class Solution {
    public String interpret(String command) {
        char[] buf = command.toCharArray();
        StringBuilder sb = new StringBuilder();
        int idx = 0;
        while (idx != buf.length) {
            if (buf[idx] == 'G') {
                sb.append("G");
                idx += 1;
            } else if (buf[idx] == '(') {
                if (buf[idx + 1] == ')') {
                    sb.append("o");
                    idx += 2;
                } else if (buf[idx + 1] == 'a') {
                    sb.append("al");
                    idx += 4;
                }
            }
        }
        return sb.toString();
    }
}
// @lc code=end
