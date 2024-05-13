/*
 * @lc app=leetcode id=2108 lang=cpp
 *
 * [2108] Find First Palindromic String in the Array
 */

// @lc code=start

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto s : words) {
            if (isPalindromic(s)) {
                return s;
            }
        }
        return "";
    }

    bool isPalindromic(const string& s) {
        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }
};
// @lc code=end
