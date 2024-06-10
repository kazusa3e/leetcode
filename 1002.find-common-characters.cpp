/*
 * @lc app=leetcode id=1002 lang=cpp
 *
 * [1002] Find Common Characters
 */

// @lc code=start

#include <algorithm>
#include <array>
#include <numeric>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        using container_t = array<unsigned, 26>;
        vector<container_t> stats;
        transform(words.begin(), words.end(), back_inserter(stats), [&](const string& s) {
            container_t container = {0};
            for_each(s.begin(), s.end(), [&](char ch) { container[ch - 'a'] += 1; });
            return container;
        });
        container_t initial;
        initial.fill(numeric_limits<unsigned>::max());
        container_t res = accumulate(stats.begin(), stats.end(), initial, [](const container_t &acc, const container_t &curr) {
            container_t m = {0};
            transform(acc.begin(), acc.end(), curr.begin(), m.begin(), [](unsigned a, unsigned b) {
                return min(a, b);
            });
            return m;
        });
        vector<string> ret;
        for (auto ix = 0; ix != res.size(); ++ix) {
            while (res[ix] != 0) {
                ret.push_back(string(1, static_cast<char>('a' + ix)));
                res[ix] -= 1;
            }
        }
        return ret;
    }
};
// @lc code=end
