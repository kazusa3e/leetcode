/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int, unsigned> m;
        for_each(nums.begin(), nums.end(), [&](const int el) {
            m[el] += 1;
        });
        auto pos = nums.begin();
        fill(pos, pos + m[0], 0);
        fill(pos + m[0], pos + m[0] + m[1], 1);
        fill(pos + m[0] + m[1], nums.end(), 2);
    }
};
// @lc code=end
