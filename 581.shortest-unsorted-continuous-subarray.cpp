/*
 * @lc app=leetcode id=581 lang=cpp
 *
 * [581] Shortest Unsorted Continuous Subarray
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int m_min = numeric_limits<int>::max(),
            m_max = numeric_limits<int>::min();

        int min_idx = -1, max_idx = -1;
        for (int ix = 0; ix != nums.size(); ++ix) {
            if (nums[ix] >= m_max) m_max = nums[ix];
            else max_idx = ix;
        }

        if (max_idx == -1) return 0;

        for (int ix = nums.size() - 1; ix >= 0; --ix) {
            if (nums[ix] <= m_min) m_min = nums[ix];
            else min_idx = ix;
        }

        return max_idx - min_idx + 1;
    }
};
// @lc code=end
