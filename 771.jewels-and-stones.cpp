/*
 * @lc app=leetcode id=771 lang=cpp
 *
 * [771] Jewels and Stones
 */

// @lc code=start
#include <algorithm>
#include <cctype>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> umap(52, false);
        auto to_idx = [](char ch) -> unsigned {
            if (isupper(ch)) return ch - 'A';
            if (islower(ch)) return ch - 'a' + 26;
            return {};
        };
        for (const auto &ch : jewels) umap[to_idx(ch)] = true;
        return count_if(stones.cbegin(), stones.cend(), [&](char ch) {
            return umap[to_idx(ch)];
        });
    }
};
// @lc code=end
