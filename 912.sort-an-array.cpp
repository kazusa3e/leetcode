/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return nums;
    }
};
// @lc code=end
