/*
 * @lc app=leetcode id=1431 lang=cpp
 *
 * [1431] Kids With the Greatest Number of Candies
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        auto m_max = max_element(candies.begin(), candies.end());
        vector<bool> ret(candies.size(), false);
        for (int ix = 0; ix != candies.size(); ++ix) {
            if (candies[ix] + extraCandies >= *m_max) ret[ix] = true;
        }
        return ret;
    }
};
// @lc code=end
