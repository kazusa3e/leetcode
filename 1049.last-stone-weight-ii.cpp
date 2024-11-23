/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        unsigned sum = accumulate(stones.begin(), stones.end(), 0);

        vector<unsigned> dp(sum / 2 + 1, 0);
        for (unsigned i = 0; i != stones.size(); ++i) {
            for (unsigned j = sum / 2; j >= stones[i]; --j) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp.back() * 2;
    }
};
// @lc code=end
