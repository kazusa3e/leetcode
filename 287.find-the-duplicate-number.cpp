/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 */

// @lc code=start

#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (auto el : nums) {
            if (auto pos = seen.find(el); pos != seen.end()) return el;
            seen.insert(el);
        }
        return -1;
    }
};
// @lc code=end
