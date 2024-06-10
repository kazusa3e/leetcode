/*
 * @lc app=leetcode id=925 lang=cpp
 *
 * [925] Long Pressed Name
 */

// @lc code=start

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        auto fn = [](const string &s) -> vector<pair<char, unsigned>> {
            vector<pair<char, unsigned>> ret;
            auto iter = s.begin(), j = iter;
            while (iter != s.end()) {
                while (*j == *iter) j += 1;
                ret.push_back(make_pair(*iter, distance(iter, j)));
                iter = j;
            }
            return ret;
        };
        vector<pair<char, unsigned>> s1 = fn(name), s2 = fn(typed);
        if (s1.size() != s2.size()) return false;
        for (int ix = 0; ix != s1.size(); ++ix) {
            if (s2[ix].first != s1[ix].first) return false;
            if (s2[ix].second < s1[ix].second) return false;
        }
        return true;
    }
};
// @lc code=end
