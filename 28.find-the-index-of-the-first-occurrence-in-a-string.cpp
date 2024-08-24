/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
        auto next = evaluate_next(needle);
        unsigned i = 0, j = 0;
        while (true) {
            if (j == needle.size()) return i - j;
            if (i == haystack.size()) return -1;
            if (haystack[i] == needle[j]) {
                i += 1; j += 1;
            } else {
                (j == 0) ? i += 1 : j = next[j - 1];
            }
        }
        return -1;
    }

    vector<unsigned> evaluate_next(const string &pattern) {
        vector<unsigned> ret(pattern.size(), 0);
        unsigned j = 0;
        for (unsigned i = 1; i != pattern.size(); ++i) {
            while (j != 0 && pattern[i] != pattern[j]) j = ret[j - 1];
            if (pattern[i] == pattern[j]) j += 1;
            ret[i] = j;
        }
        return ret;
    }
};
// @lc code=end
