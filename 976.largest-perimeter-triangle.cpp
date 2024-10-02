/*
 * @lc app=leetcode id=976 lang=cpp
 *
 * [976] Largest Perimeter Triangle
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater {});
        for (auto iter = nums.begin(); iter != nums.end() - 2; ++iter) {
            auto a = *iter, b = *(iter + 1), c = *(iter + 2);
            if (b + c > a) return a + b + c;
        }
        return 0;
    }
};
// @lc code=end
