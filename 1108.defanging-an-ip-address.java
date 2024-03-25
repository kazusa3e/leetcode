/*
 * @lc app=leetcode id=1108 lang=java
 *
 * [1108] Defanging an IP Address
 */

// @lc code=start
class Solution {
    public String defangIPaddr(String address) {
        StringBuffer sb = new StringBuffer();
        for (char ch: address.toCharArray()) {
            if (ch >= '0' && ch <= '9') {
                sb.append(ch);
            }
            if (ch == '.') {
                sb.append("[.]");
            }
        }
        return sb.toString();
    }
}
// @lc code=end
