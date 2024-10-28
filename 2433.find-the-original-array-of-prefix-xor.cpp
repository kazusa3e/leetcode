/*
 * @lc app=leetcode id=2433 lang=cpp
 *
 * [2433] Find The Original Array of Prefix Xor
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> ret(pref.size(), 0); ret[0] = pref[0];
        for (unsigned ix = 1; ix != pref.size(); ++ix) {
            ret[ix] = pref[ix] ^ pref[ix - 1];
        }
        return ret;
    }
};
// @lc code=end
