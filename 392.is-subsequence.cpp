/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) return true;
        if (t.empty()) return false;
        auto i = s.begin();
        for (auto iter = t.begin(); iter != t.end(); ++iter) {
            if (*i == *iter) i += 1;
        }
        return i == s.end();
    }
};
// @lc code=end
