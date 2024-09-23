/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

// @lc code=start

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candies(ratings.size(), 1);
        for (int ix = 1; ix != ratings.size(); ++ix) {
            if (ratings[ix] > ratings[ix - 1]) {
                candies[ix] = candies[ix - 1] + 1;
            }
        }
        for (int ix = ratings.size() - 2; ix >= 0; --ix) {
            if (ratings[ix] > ratings[ix + 1]) {
                candies[ix] = max(candies[ix + 1] + 1, candies[ix]);
            }
        }
        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// @lc code=end
