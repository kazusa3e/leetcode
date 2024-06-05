/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 */

// @lc code=start

#include <string>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (auto iter = s.begin(); iter != s.end();) {
            if (!isalnum(*iter)) {
                iter = s.erase(iter);
                continue;
            }
            if (isupper(*iter)) {
                *iter = tolower(*iter);
                iter += 1;
                continue;
            }
            iter += 1;
        }
        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }
};
// @lc code=end
