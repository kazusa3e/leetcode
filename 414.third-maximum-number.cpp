/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater {});
        const auto pos = unique(nums.begin(), nums.end());
        if (distance(nums.begin(), pos) < 3) return nums.front();
        return nums[2];
    }
};
// @lc code=end
