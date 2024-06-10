/*
 * @lc app=leetcode id=205 lang=cpp
 *
 * [205] Isomorphic Strings
 */

// @lc code=start

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map1, map2;
        for (int i = 0, j = 0; i != s.size(); ++i, ++j) {
            if (auto pos = map1.find(s[i]); pos == map1.end()) {
                map1[s[i]] = t[j];
            }
            if (auto pos = map2.find(t[j]); pos == map2.end()) {
                map2[t[j]] = s[i];
            }
            if (map1[s[i]] != t[j] || map2[t[j]] != s[i]) return false;
        }
        return true;
    }
};
// @lc code=end
