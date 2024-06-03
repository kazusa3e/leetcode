/*
 * @lc app=leetcode id=561 lang=cpp
 *
 * [561] Array Partition
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for (auto iter = nums.begin(); iter < nums.end(); iter += 2) {
            sum += *iter;
        }
        return sum;
    }
};
// @lc code=end
