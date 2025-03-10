/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x == 0) return true;

        int t = x;
        long rev = x % 10; x /= 10;
        while (x != 0) {
            rev *= 10; rev += x % 10; x /= 10;
        }
        return t == rev;
    }
};
// @lc code=end
