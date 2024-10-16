/*
 * @lc app=leetcode id=1732 lang=cpp
 *
 * [1732] Find the Highest Altitude
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> presum(gain.size() + 1);
        presum[0] = 0;
        partial_sum(gain.begin(), gain.end(), presum.begin() + 1);
        return *max_element(presum.begin(), presum.end());
    }

};
// @lc code=end
