/*
 * @lc app=leetcode id=268 lang=cpp
 *
 * [268] Missing Number
 */

// @lc code=start
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<bool> bitmap(nums.size(), false);
        for (const auto &el : nums) bitmap[el] = true;
        return distance(bitmap.cbegin(), find(bitmap.cbegin(), bitmap.cend(), false));
    }
};
// @lc code=end
