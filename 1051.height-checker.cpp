/*
 * @lc app=leetcode id=1051 lang=cpp
 *
 * [1051] Height Checker
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        auto expected = heights;
        sort(expected.begin(), expected.end());
        int ret = 0;
        for (auto ix = 0ull; ix != heights.size(); ++ix) {
            if (heights[ix] != expected[ix]) ++ret;
        }
        return ret;
    }
};
// @lc code=end
