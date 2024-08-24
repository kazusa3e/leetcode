/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t {s};
        t += t;
        t.erase(t.begin()); t.erase(t.end() - 1);
        return (t.find(s) != string::npos);
    }
};
// @lc code=end
