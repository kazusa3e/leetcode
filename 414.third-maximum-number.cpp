/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, greater<>> s { nums.begin(), nums.end() };
        auto pos = s.cbegin();
        if (s.size() < 3) return *pos;
        ++pos; ++pos; return *pos;
    }
};
// @lc code=end
