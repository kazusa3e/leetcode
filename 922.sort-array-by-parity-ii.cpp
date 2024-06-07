/*
 * @lc app=leetcode id=922 lang=cpp
 *
 * [922] Sort Array By Parity II
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        long even_index = 0L, odd_index = 1L;
        while (even_index < nums.size()) {
            if (nums[even_index] % 2 == 1) {
                while (nums[odd_index] % 2 == 1) {
                    odd_index += 2;
                }
                swap(nums[even_index], nums[odd_index]);
            }
            even_index += 2;
        }
        return nums;
    }
};
// @lc code=end
