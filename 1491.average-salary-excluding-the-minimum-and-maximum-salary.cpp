/*
 * @lc app=leetcode id=1491 lang=cpp
 *
 * [1491] Average Salary Excluding the Minimum and Maximum Salary
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        auto min_el = min_element(salary.begin(), salary.end()),
            max_el = max_element(salary.begin(), salary.end());
        return accumulate(salary.begin(), salary.end(), 0, [&](int a, int b) {
            return (b != *min_el && b != *max_el) ? a + b : a;
        }) / (double) (salary.size() - 2);
    }
};
// @lc code=end
