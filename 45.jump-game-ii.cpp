/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start

#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return true;
        if (nums[0] == 0) return false;
        unsigned curr = 0, steps = 0;
        while (curr < nums.size() - 1) {
            vector<pair<unsigned, unsigned>> tmp;
            for (unsigned i = curr + 1; i != min((unsigned) nums.size() - 1, curr + nums[curr] + 1); ++i) {
                tmp.push_back({i + nums[i], i});
            }
            curr = max_element(tmp.begin(), tmp.end())->second; steps += 1;
        }
        return steps;
    }
};
// @lc code=end
