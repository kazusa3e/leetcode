/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        auto ans = accumulate(nums.cbegin(), nums.cend(), 0, bit_xor {});
        for (auto ix = 0ull; ix <= nums.size(); ++ix) ans ^= ix;
        return ans;
    }
};
// @lc code=end
