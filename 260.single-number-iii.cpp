/*
 * @lc app=leetcode id=260 lang=cpp
 *
 * [260] Single Number III
 */

// @lc code=start

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        const unsigned int tmp = accumulate(nums.begin(), nums.end(), 0, bit_xor {});
        const unsigned int mask = tmp & -tmp; int k = 0;
        for_each(nums.begin(), nums.end(), [&](const int el) {
            if (mask & el) k ^= el;
        });
        return { (int) k, (int) tmp ^ k };
    }
};
// @lc code=end
