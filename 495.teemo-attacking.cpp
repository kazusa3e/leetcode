/*
 * @lc app=leetcode id=495 lang=cpp
 *
 * [495] Teemo Attacking
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        for (auto iter = timeSeries.cbegin(); iter != timeSeries.cend(); ++iter) {
            if (iter + 1 == timeSeries.cend()) {
                total += duration;
            } else {
                total += (*iter + duration < *(iter + 1)) ? duration : *(iter + 1) - *iter;
            }
        }
        return total;
    }
};
// @lc code=end
