/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto rptr = nums.begin(), wptr = nums.begin();
        while (rptr != nums.end()) {
            if (rptr == nums.begin() || *rptr != *(wptr - 1)) {
                *wptr = *rptr;
                wptr += 1;
            }
            rptr += 1;
        }
        nums.erase(wptr, nums.end());
        return wptr - nums.begin();
    }
};
// @lc code=end
