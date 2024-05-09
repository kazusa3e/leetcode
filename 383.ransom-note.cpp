/*
 * @lc app=leetcode id=383 lang=cpp
 *
 * [383] Ransom Note
 */

// @lc code=start

#include <string>
#include <array>

using namespace std;

class Solution {
public:
    using table_type = array<int, 26>;
    bool canConstruct(string ransomNote, string magazine) {
        table_type rt = buildTable(ransomNote), mt = buildTable(magazine);
        transform(rt.begin(), rt.end(), mt.begin(), mt.begin(), [](const auto a, const auto b) {
            return b - a;
        });
        return all_of(mt.begin(), mt.end(), [](const auto e) {
            return e >= 0;
        });
    }
    table_type buildTable(const string &s) {
        table_type t;
        for (auto ch: s) {
            t[ch - 'a'] += 1;
        }
        return t;
    }
};
// @lc code=end
