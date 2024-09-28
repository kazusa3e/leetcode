/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 */

// @lc code=start

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string toLowerCase(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }
};
// @lc code=end
