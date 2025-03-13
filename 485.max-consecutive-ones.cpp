/*
 * @lc app=leetcode id=485 lang=cpp
 *
 * [485] Max Consecutive Ones
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        auto pos = find(nums.cbegin(), nums.cend(), 1);
        if (pos == nums.cend()) return 0;
        unsigned curr_win = 1, max_win = 1;
        for (++pos; pos != nums.cend(); ++pos) {
            if (*pos == 0) curr_win = 0;
            else {
                ++curr_win; max_win = max(max_win, curr_win);
            }
        }
        return max_win;
    }
};
// @lc code=end
