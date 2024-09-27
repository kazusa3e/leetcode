/*
 * @lc app=leetcode id=389 lang=cpp
 *
 * [389] Find the Difference
 */

// @lc code=start

#include <string>
#include <array>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        auto sm = build_count_map(s), tm = build_count_map(t);
        for (auto ix = 0; ix != 26; ++ix) {
            if (sm[ix] != tm[ix]) {
                return 'a' + ix;
            }
        }
        return '\0';
    }

    array<unsigned, 26> build_count_map(const string &s) {
        array<unsigned, 26> ret = {
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        };
        for (auto ch : s) {
            ret[ch - 'a'] += 1;
        }
        return ret;
    }
};
// @lc code=end
