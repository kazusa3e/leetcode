/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen;
        for (auto ix = 0; ix != nums.size(); ++ix) {
            auto iter = seen.find(target - nums.at(ix));
            if (iter != seen.end()) {
                return {ix, iter->second};
            }
            seen.insert(make_pair(nums.at(ix), ix));
        }
        return {-1, -1};
    }
};
// @lc code=end
