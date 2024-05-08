/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start

#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        auto rptr = nums.begin(), wptr = nums.begin();
        while (rptr != nums.end()) {
            if (*rptr != val) {
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
