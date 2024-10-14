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
        auto iter = s.begin();
        for (auto i = t.begin(); i != t.end(); ++i) {
            if (*i == *iter) ++iter;
            if (iter == s.end()) return true;
        }
        return false;
    }
};
// @lc code=end
