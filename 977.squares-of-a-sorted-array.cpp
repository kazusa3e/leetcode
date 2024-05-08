/*
 * @lc app=leetcode id=977 lang=cpp
 *
 * [977] Squares of a Sorted Array
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ret;
        auto inserter = back_inserter(ret);
        auto lptr = nums.begin(), rptr = nums.end();
        while (lptr < rptr) {
            auto lval = abs(*lptr), rval = abs(*(rptr - 1));
            if (lval > rval) {
                *inserter = lval * lval;
                lptr += 1;
            } else {
                *inserter = rval * rval;
                rptr -= 1;
            }
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
// @lc code=end
