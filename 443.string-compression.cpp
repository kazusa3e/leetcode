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
        vector<char> ret;
        auto iter = chars.begin();
        while (iter != chars.end()) {
            auto pos = find_if(iter, chars.end(), [&iter](char ch) { return ch != *iter; });
            ret.push_back(*iter);
            auto dif = distance(iter, pos);
            if (dif != 1) {
                vector<char> tmp;
                while (dif != 0) {
                    tmp.push_back((dif % 10) + '0');
                    dif /= 10;
                }
                reverse(tmp.begin(), tmp.end());
                copy(tmp.begin(), tmp.end(), back_inserter(ret));
            }
            iter = pos;
        }
        copy(ret.begin(), ret.end(), chars.begin());
        return ret.size();
    }
};
// @lc code=end
