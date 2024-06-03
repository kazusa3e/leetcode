/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

// @lc code=start

#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> seen;
        for (auto elem: nums) {
            if (auto pos = seen.find(elem); pos != seen.end()) {
                return true;
            }
            seen.insert(elem);
        }
        return false;
    }
};
// @lc code=end
