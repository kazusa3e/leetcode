/*
 * @lc app=leetcode id=1221 lang=cpp
 *
 * [1221] Split a String in Balanced Strings
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int ret = 0;
        unsigned bias = 0;
        for (auto ch : s) {
            bias = (ch == 'R') ? bias + 1 : bias - 1;
            if (bias == 0) ret += 1;
        }
        return ret;
    }
};
// @lc code=end
