/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices.front();
        int profit = 0;
        int max_profit = 0;
        for (auto iter = prices.begin() + 1; iter != prices.end(); ++iter) {
            profit = *iter - buy;
            max_profit = max(max_profit, profit);
            if (profit < 0) buy = *iter;
        }
        return max_profit;
    }
};
// @lc code=end
