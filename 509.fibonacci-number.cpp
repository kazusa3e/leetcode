/*
 * @lc app=leetcode id=509 lang=cpp
 *
 * [509] Fibonacci Number
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        int a = 0, b = 1;
        int idx = 0;
        while (idx != n) {
            int t = a + b;
            a = b;
            b = t;
            idx += 1;
        }
        return a;
    }
};
// @lc code=end
