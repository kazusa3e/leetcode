/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 */

// @lc code=start

#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        auto l = s.begin(), r = s.end() - 1;
        while (l < r) {
            if (*l == *r) {
                l += 1; r -= 1;
            } else {
                return isPalindrome(string{s.begin(), l} + string{l + 1, s.end()}) || isPalindrome(string{s.begin(), r} + string{r + 1, s.end()});
            }
        }
        return true;
    }

    bool isPalindrome(const string &s) {
        return equal(s.begin(), s.begin() + (s.size() / 2), s.rbegin());
    }
};
// @lc code=end
