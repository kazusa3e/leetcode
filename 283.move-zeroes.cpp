/*
 * @lc app=leetcode id=283 lang=cpp
 *
 * [283] Move Zeroes
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto rptr = nums.begin(), wptr = nums.begin();
        while (rptr != nums.end()) {
            if (*rptr != 0) {
                *wptr = *rptr;
                wptr += 1;
            }
            rptr += 1;
        }
        std::fill(wptr, nums.end(), 0);
    }
};
// @lc code=end
