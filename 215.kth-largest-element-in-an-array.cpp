/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater {});
        return nums[k - 1];
    }
};
// @lc code=end
