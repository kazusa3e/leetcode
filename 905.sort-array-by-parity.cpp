/*
 * @lc app=leetcode id=905 lang=cpp
 *
 * [905] Sort Array By Parity
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        for (auto l = nums.begin(), r = nums.end() - 1; l <= r; ) {
            if (*l % 2 == 0) ++l;
            else if (*r % 2 == 1) --r;
            else {
                swap(*l, *r); ++l; --r;
            }
        }
        return nums;
    }
};
// @lc code=end
