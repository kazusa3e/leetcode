/*
 * @lc app=leetcode id=1995 lang=cpp
 *
 * [1995] Count Special Quadruplets
 */

// @lc code=start

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        unsigned cnt = 0;
        unordered_map<int, unsigned> count;
        count.insert(make_pair(nums[nums.size() - 1] - nums[nums.size() - 2], 1));
        for (unsigned b = nums.size() - 3; b > 0; --b) {
            for (int a = b - 1; a >= 0; --a) {
                cnt += count[nums[a] + nums[b]];
            }
            for (int x = nums.size() - 1; x > b; --x) {
                count[nums[x] - nums[b]]++;
            }
        }
        return cnt;
    }
};
// @lc code=end
