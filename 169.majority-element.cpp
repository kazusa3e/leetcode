/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unsigned count = 0;
        int candidate = nums[0];
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (count == 0) candidate = *iter;
            if (*iter == candidate) count += 1;
            else count -= 1;
        }
        return candidate;
    }
};
// @lc code=end
