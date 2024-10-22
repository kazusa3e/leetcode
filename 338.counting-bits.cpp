/*
 * @lc app=leetcode id=338 lang=cpp
 *
 * [338] Counting Bits
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret(n + 1); ret[0] = 0;
        for (unsigned ix = 1; ix <= n; ++ix) {
            // ret[ix] = ret[ix / 2] + (ix % 2);
            ret[ix] = ret[ix & (ix - 1)] + 1;
        }
        return ret;
    }
};
// @lc code=end
