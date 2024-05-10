/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> seen12, seen34;
        for(auto i = nums1.begin(); i != nums1.end(); ++i) {
            for (auto j = nums2.begin(); j != nums2.end(); ++j) {
                seen12[*i + *j] += 1;
            }
        }
        for(auto i = nums3.begin(); i != nums3.end(); ++i) {
            for (auto j = nums4.begin(); j != nums4.end(); ++j) {
                seen34[*i + *j] += 1;
            }
        }
        int ret = 0;
        for (auto i = seen12.begin(); i != seen12.end(); ++i) {
            auto j = seen34.find(-i->first);
            if (j != seen34.end()) {
                ret += i->second * j->second;
            }
        }
        return ret;
    }
};
// @lc code=end
