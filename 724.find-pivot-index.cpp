/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        vector<int> prefix_sum(nums.size()), suffix_sum(nums.size());
        partial_sum(nums.begin(), nums.end(), prefix_sum.begin());
        partial_sum(nums.rbegin(), nums.rend(), suffix_sum.rbegin());
        for (unsigned ix = 0; ix != nums.size(); ++ix) {
            if (prefix_sum[ix] == suffix_sum[ix]) return ix;
        }
        return -1;
    }
};
// @lc code=end
