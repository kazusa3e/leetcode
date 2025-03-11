/*
 * @lc app=leetcode id=1929 lang=cpp
 *
 * [1929] Concatenation of Array
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        auto sz = nums.size();
        nums.resize(sz * 2);
        copy(nums.begin(), nums.begin() + sz, nums.begin() + sz);
        return nums;
    }
};
// @lc code=end
