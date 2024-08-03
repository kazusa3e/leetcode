/*
 * @lc app=leetcode id=1460 lang=cpp
 *
 * [1460] Make Two Arrays Equal by Reversing Subarrays
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        std::sort(target.begin(), target.end());
        std::sort(arr.begin(), arr.end());
        return std::equal(target.begin(), target.end(), arr.begin(), arr.end());
    }
};
// @lc code=end
