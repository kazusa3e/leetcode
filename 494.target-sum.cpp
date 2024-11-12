/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        const unsigned sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum + target) % 2 == 1) return 0;
        const unsigned l = (sum + target) / 2;
        unsigned cnt {};
        backtracking(nums, 0, 0, cnt, l);
        return cnt;
    }

    void backtracking(const vector<int> &nums, unsigned start, unsigned subsum, unsigned &cnt, const unsigned target) {
        if (subsum == target) {
            cnt += 1;
        }
        for (unsigned idx = start; idx != nums.size(); ++idx) {
            subsum += nums[idx];
            backtracking(nums, idx + 1, subsum, cnt, target);
            subsum -= nums[idx];
        }
    }
};
// @lc code=end
