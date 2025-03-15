/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */

// @lc code=start

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        const auto pos = copy_if(nums.begin(), nums.end(), nums.begin(), [&val](const auto &el) {
            return el != val;
        });
        nums.erase(pos, nums.end());
        return nums.size();
    }
};
// @lc code=end
