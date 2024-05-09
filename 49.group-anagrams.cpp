/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start

#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for_each(strs.begin(), strs.end(), [&m](const string s) {
            vector<char> chars;
            copy(s.begin(), s.end(), back_inserter(chars));
            sort(chars.begin(), chars.end());
            string key {chars.begin(), chars.end()};
            m[key].push_back(s);
        });
        vector<vector<string>> ret;
        for_each(m.begin(), m.end(), [&ret](const auto p) {
            ret.push_back(p.second);
        });
        return ret;
    }
};
// @lc code=end
