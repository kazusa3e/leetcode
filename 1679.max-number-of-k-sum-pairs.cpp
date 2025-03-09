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
        auto l = nums.begin();
        auto r = upper_bound(nums.crbegin(), nums.crend(), k, greater {}).base() - 1;
        int num_operator = 0;
        while (l < r) {
            auto s = *l + *r;
            if (s == k) {
                ++l; --r; num_operator += 1;
            } else if (s < k) ++l;
            else --r;
        }
        return num_operator;
    }
};
// @lc code=end
