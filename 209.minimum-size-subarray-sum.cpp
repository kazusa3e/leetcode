/*
 * @lc app=leetcode id=209 lang=cpp
 *
 * [209] Minimum Size Subarray Sum
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        auto l = nums.begin(), r = nums.begin() + 1;
        int subsum = nums.at(0);
        int minwinsz = INT_MAX;
        while (r <= nums.end()) {
            while (subsum >= target) {
                minwinsz = min(minwinsz, static_cast<int>(r - l));
                subsum -= *l;
                l += 1;
            }
            if (r == nums.end()) {
                break;
            }
            subsum += *r;
            r += 1;
        }
        return (minwinsz == INT_MAX) ? 0 : minwinsz;
    }
};
// @lc code=end
