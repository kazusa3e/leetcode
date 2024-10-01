/*
 * @lc app=leetcode id=1523 lang=cpp
 *
 * [1523] Count Odd Numbers in an Interval Range
 */

// @lc code=start
class Solution {
public:
    int countOdds(int low, int high) {
        int ret = 0;
        for (int i = low; i <= high; ++i) {
            if (i % 2 == 1) ret += 1;
        }
        return ret;
    }
};
// @lc code=end
