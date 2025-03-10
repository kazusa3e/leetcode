/*
 * @lc app=leetcode id=1295 lang=cpp
 *
 * [1295] Find Numbers with Even Number of Digits
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        auto check = [](int n) -> bool {
            return (n >= 10 && n <= 99)
                || (n >= 1000 && n <= 9999)
                || (n >= 100000 && n <= 999999);
        };
        return count_if(nums.begin(), nums.end(), check);
    }
};
// @lc code=end
