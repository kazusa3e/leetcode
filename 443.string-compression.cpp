/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        auto iter = chars.begin();
        while (iter != chars.end()) {
            auto pos = find_if(iter, chars.end(), [&iter](char ch) { return ch != *iter; });
            if (distance(iter, pos) == 1) {
                iter = pos; continue;
            }
            auto dif = distance(iter, pos); auto s = to_string(dif);
            copy(s.begin(), s.end(), iter + 1);
            chars.erase(iter + s.size(), pos);
            iter += s.size();
        }
        return chars.size();
    }
};
// @lc code=end
