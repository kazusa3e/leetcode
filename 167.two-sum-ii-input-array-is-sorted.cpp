/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start

#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        auto left = numbers.begin(),
             right = numbers.end();
        while (left < right) {
            if (*left + *(prev(right)) < target) {
                left = next(left);
            } else if (*left + *(prev(right)) > target) {
                right = prev(right);
            } else {
                return {static_cast<int>(left - numbers.begin() + 1), static_cast<int>(right - numbers.begin())};
            }
        }
        return {-1, -1};
    }
};
// @lc code=end
