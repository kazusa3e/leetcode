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
        auto subsum = accumulate(nums.cbegin(), nums.cbegin() + k, 0);
        auto max_subsum = subsum;
        for (auto l = nums.cbegin(), r = nums.cbegin() + k; r != nums.cend(); ++l, ++r) {
            subsum = subsum - *l + *r;
            max_subsum = max(max_subsum, subsum);
        }
        return (double) max_subsum / k;
    }
};
// @lc code=end
