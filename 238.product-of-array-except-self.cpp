/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 */

// @lc code=start

#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        unsigned num_zeros = 0;
        decltype(nums.begin()) zero_pos;
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (*iter == 0) {
                zero_pos = iter; num_zeros += 1;
            } else {
                prod *= *iter;
            }
        }
        if (num_zeros > 1) return vector<int>(nums.size(), 0);
        if (num_zeros == 1) {
            fill(nums.begin(), nums.end(), 0);
            *zero_pos = prod;
            return nums;
        }
        transform(nums.begin(), nums.end(), nums.begin(), [&prod](const int &val) {
            return prod / val;
        });
        return nums;
    }
};
// @lc code=end
