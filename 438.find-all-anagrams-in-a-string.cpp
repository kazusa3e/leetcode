/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 */

// @lc code=start

#include <vector>
#include <string>
#include <array>

using namespace std;

class Solution {
public:
    using table_type = array<int, 26>;
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) {
            return {};
        }
        table_type pt = buildTable(p);
        table_type st;
        auto l = 0, r = 0;
        while (r - l != p.size()) {
            st[s.at(r) - 'a'] += 1;
            r += 1;
        }
        vector<int> ret;
        while (r <= s.size()) {
            if (isAnagram(st, pt)) {
                ret.push_back(l);
            }
            st[s.at(l) - 'a'] -= 1;
            l += 1;
            if (r == s.size()) {
                break;
            }
            st[s.at(r) - 'a'] += 1;
            r += 1;
        }
        return ret;
    }
    table_type buildTable(const string &s) {
        table_type t;
        for (auto ch: s) {
            t[ch - 'a'] += 1;
        }
        return t;
    }
    bool isAnagram(const table_type &a, const table_type &b) {
        table_type t;
        copy(a.begin(), a.end(), t.begin());
        transform(a.begin(), a.end(), b.begin(), t.begin(), [](const auto x, const auto y) {
            return x - y;
        });
        return all_of(t.begin(), t.end(), [](const auto x) {
            return x == 0;
        });
    }

};
// @lc code=end
