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
        vector<bool> ret(candies.size(), false);
        const auto max_el = *max_element(candies.cbegin(), candies.cend());
        transform(candies.cbegin(), candies.cend(), ret.begin(), [&](const auto el) {
            return el + extraCandies >= max_el;
        });
        return ret;
    }
};
// @lc code=end
