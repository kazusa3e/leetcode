/*
 * @lc app=leetcode id=3158 lang=cpp
 *
 * [3158] Find the XOR of Numbers Which Appear Twice
 */

// @lc code=start

#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_set<int> uset { nums.begin(), nums.end() };
        return accumulate(nums.begin(), nums.end(), accumulate(uset.begin(), uset.end(), 0, bit_xor {}), bit_xor {});
    }
};
// @lc code=end
