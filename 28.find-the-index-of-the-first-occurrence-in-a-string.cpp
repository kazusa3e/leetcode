/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;
        if (haystack.size() < needle.size()) return -1;
        auto start_pos = haystack.begin();
        auto i = start_pos, j = needle.begin();
        while (j != needle.end()) {
            if (*i == *j) {
                i += 1; j += 1;
            } else {
                start_pos += 1;
                if (start_pos > haystack.end() - needle.size()) return -1;
                i = start_pos; j = needle.begin();
            }
        }
        return start_pos - haystack.begin();
    }
};
// @lc code=end
