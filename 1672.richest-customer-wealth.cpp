/*
 * @lc app=leetcode id=1672 lang=cpp
 *
 * [1672] Richest Customer Wealth
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        vector<int> amount;
        transform(accounts.begin(), accounts.end(), back_inserter(amount), [](const vector<int> &a) {
            return accumulate(a.begin(), a.end(), 0);
        });
        return *max_element(amount.begin(), amount.end());
    }
};
// @lc code=end
