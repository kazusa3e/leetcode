/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start

#include <vector>
#include <map>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int presum = 0;
        int total_sum = 0;
        for (int i = 0; i != gas.size(); ++i) {
            presum += gas[i] - cost[i];
            total_sum += gas[i] - cost[i];
            if (presum < 0) {
                start = i + 1;
                presum = 0;
            }
        }
        return (total_sum >= 0) ? start : -1;
    }
};
// @lc code=end
