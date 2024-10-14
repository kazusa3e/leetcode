/*
 * @lc app=leetcode id=1679 lang=cpp
 *
 * [1679] Max Number of K-Sum Pairs
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        unsigned num_opers = 0;
        auto l = nums.begin(), r = nums.end() - 1;
        while (l < r) {
            if (*l + *r == k) {
                ++num_opers; ++l; --r;
                continue;
            }
            if (*l + *r < k) {
                ++l; continue;
            }
            if (*l + *r > k) {
                --r; continue;
            }
        }
        return num_opers;
    }
};
// @lc code=end
