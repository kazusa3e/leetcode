/*
 * @lc app=leetcode id=20 lang=java
 *
 * [20] Valid Parentheses
 */

// @lc code=start

import java.util.Stack;

class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (char ch : s.toCharArray()) {
            if (ch == '(') {
                stack.add(')');
            }
            if (ch == '[') {
                stack.add(']');
            }
            if (ch == '{') {
                stack.add('}');
            }
            if (ch == ')' || ch == ']' || ch == '}') {
                if (stack.size() == 0) {
                    return false;
                }
                if (stack.pop() != ch) {
                    return false;
                }
            }
        }
        return (stack.size() == 0);
    }
}
// @lc code=end
