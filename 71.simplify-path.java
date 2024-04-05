/*
 * @lc app=leetcode id=71 lang=java
 *
 * [71] Simplify Path
 */

// @lc code=start

import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public String simplifyPath(String path) {
        Deque<String> deque = new ArrayDeque<>();
        for (String s : path.split("/")) {
            if (s.equals(""))
                continue;
            if (s.equals("."))
                continue;
            if (s.equals("..")) {
                deque.pollLast();
                continue;
            }
            deque.addLast(s);
        }

        return "/" + String.join("/", deque);
    }
}
// @lc code=end
