/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start

#include <vector>
#include <string>
#include <algorithm>
#include <array>
#include <numeric>
#include <limits>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        using record_t = array<unsigned, 26>;
        vector<record_t> records;
        transform(words.begin(), words.end(), back_inserter(records), [](const string &s) {
            record_t r {};
            for_each(s.begin(), s.end(), [&r](char ch) {
                r[ch - 'a'] += 1;
            });
            return r;
        });
        record_t initial {};
        initial.fill(numeric_limits<unsigned>::max());
        record_t common = accumulate(records.begin(), records.end(), initial, [](const record_t &acc, const record_t &r) {
            record_t ret {};
            transform(acc.begin(), acc.end(), r.begin(), ret.begin(), [](unsigned a, unsigned b) {
                return min(a, b);
            });
            return ret;
        });
        vector<string> ret;
        for (unsigned ix = 0; ix != 26; ++ix) {
            if (common[ix] != 0) {
                fill_n(back_inserter(ret), common[ix], string (1, 'a' + ix));
            }
        }
        return ret;
    }
};
// @lc code=end
