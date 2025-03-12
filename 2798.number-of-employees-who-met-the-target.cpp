/*
 * @lc app=leetcode id=2798 lang=cpp
 *
 * [2798] Number of Employees Who Met the Target
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        return count_if(hours.cbegin(), hours.cend(), [&target](int h) { return h >= target; });
    }
};
// @lc code=end
