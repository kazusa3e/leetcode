/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

// @lc code=start

#include <string>
#include <array>
#include <algorithm>

using namespace std;

class Solution {
public:
    using table_type = array<int, 26>;
    bool isAnagram(string s, string t) {
        table_type ts = buildTable(s), tt = buildTable(t);
        transform(ts.begin(), ts.end(), tt.begin(), tt.begin(), [](const auto a, const auto b) {
            return a - b;
        });
        return all_of(tt.begin(), tt.end(), [](const auto e) {
            return e == 0;
        });
    }
    table_type buildTable(const string &s) {
        table_type t;
        for (auto ch : s) {
            t[ch - 'a'] += 1;
        }
        return t;
    }
};
// @lc code=end
