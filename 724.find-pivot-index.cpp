/*
 * @lc app=leetcode id=724 lang=cpp
 *
 * [724] Find Pivot Index
 */

// @lc code=start

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        long sum = accumulate(nums.begin(), nums.end(), 0L, plus {});
        long acc = 0L;
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) {
            if (acc * 2 + *iter == sum) return distance(nums.begin(), iter);
            acc += *iter;
        }
        return -1;
    }
};
// @lc code=end
