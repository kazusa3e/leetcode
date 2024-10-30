/*
 * @lc app=leetcode id=1268 lang=cpp
 *
 * [1268] Search Suggestions System
 */

// @lc code=start

#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
private:
    set<string> s;

public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        for (const auto &w : products) s.insert(w);

        vector<vector<string>> results;
        string prefix;
        for (unsigned ix = 0; ix != searchWord.size(); ++ix) {
            prefix += searchWord[ix];
            auto pos = s.lower_bound(prefix);
            vector<string> level;
            for (unsigned ix = 0; ix != 3; ++ix) {
                if (pos != s.end() && !pos->compare(0, prefix.size(), prefix)) {
                    level.push_back(*pos); ++pos;
                }
            }
            results.push_back(level);
        }
        return results;
    }
};
// @lc code=end
