/*
 * @lc app=leetcode id=1979 lang=cpp
 *
 * [1979] Find Greatest Common Divisor of Array
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        return gcd(
            *min_element(nums.cbegin(), nums.cend()),
            *max_element(nums.cbegin(), nums.cend())
        );
    }
};
// @lc code=end
