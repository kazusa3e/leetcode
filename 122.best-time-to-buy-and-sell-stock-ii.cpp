/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int acc = 0;
        for (int ix = 1; ix != prices.size(); ++ix) {
            int diff = prices[ix] - prices[ix - 1];
            if (diff > 0) acc += diff;
        }
        return acc;
    }
};
// @lc code=end
