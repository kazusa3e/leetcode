/*
 * @lc app=leetcode id=2413 lang=cpp
 *
 * [2413] Smallest Even Multiple
 */

// @lc code=start
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return (n & 0x01) ? n << 1 : n;
    }
};
// @lc code=end
