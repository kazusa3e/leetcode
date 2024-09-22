/*
 * @lc app=leetcode id=1005 lang=cpp
 *
 * [1005] Maximize Sum Of Array After K Negations
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), [](const int &a, const int &b) {
            return abs(a) > abs(b);
        });
        auto iter = nums.begin();
        for (; iter != nums.end() && k != 0; ++iter) {
            if (*iter < 0) {
                *iter = -*iter; k -= 1;
            }
        }
        if (k % 2 == 1) nums.back() *= -1;
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
// @lc code=end
