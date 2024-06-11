/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

// @lc code=start

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret;
        unsigned ix = 0;
        while (true) {
            if (ix == strs[0].size()) break;
            char ch = strs.front()[ix];
            if (all_of(strs.begin() + 1, strs.end(), [&](const string &s) {
                return s.size() > ix && s[ix] == ch;
            })) {
                ret += ch;
                ix += 1;
            } else {
                break;
            }
        }
        return ret;
    }
};
// @lc code=end
