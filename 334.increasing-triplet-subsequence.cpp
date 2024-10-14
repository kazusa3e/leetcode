/*
 * @lc app=leetcode id=334 lang=cpp
 *
 * [334] Increasing Triplet Subsequence
 */

// @lc code=start

#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = numeric_limits<int>::max(),
            min2 = numeric_limits<int>::max();
        for (auto el : nums) {
            if (el <= min1) min1 = el;
            else if (el <= min2) min2 = el;
            else return true;
        }
        return false;
    }
};
// @lc code=end
