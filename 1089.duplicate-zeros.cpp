/*
 * @lc app=leetcode id=1089 lang=cpp
 *
 * [1089] Duplicate Zeros
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        auto num_zeros = count(arr.begin(), arr.end(), 0);
        vector<int> tmp(arr.size() + num_zeros, 0);
        auto iter = tmp.begin();
        for (const auto &el : arr) {
            if (el == 0) *(iter++) = 0;
            *(iter++) = el;
        }
        copy(tmp.begin(), tmp.begin() + arr.size(), arr.begin());
    }
};
// @lc code=end
