/*
 * @lc app=leetcode id=2824 lang=cpp
 *
 * [2824] Count Pairs Whose Sum is Less than Target
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        if (nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        unsigned cnt = 0;
        for (auto l = nums.cbegin(); l != nums.cend() - 1; ++l) {
            for (auto r = l + 1; r != nums.cend(); ++r) {
                if (*l + *r < target) ++cnt;
            }
        }
        return cnt;
    }
};
// @lc code=end
