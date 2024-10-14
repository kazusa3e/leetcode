/*
 * @lc app=leetcode id=643 lang=cpp
 *
 * [643] Maximum Average Subarray I
 */

// @lc code=start

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int win = accumulate(nums.begin(), nums.begin() + k, 0);
        int max_win = win;
        auto l = nums.begin(), r = nums.begin() + k;
        while (r <= nums.end() - 1) {
            win -= *l; win += *r;
            max_win = max(win, max_win);
            ++l; ++r;
        }
        return (double) max_win / k;
    }
};
// @lc code=end
