/*
 * @lc app=leetcode id=2215 lang=cpp
 *
 * [2215] Find the Difference of Two Arrays
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1 { nums1.begin(), nums1.end() },
            s2 { nums2.begin(), nums2.end() };
        vector<int> diff1, diff2;
        set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(diff1));
        set_difference(s2.begin(), s2.end(), s1.begin(), s1.end(), back_inserter(diff2));
        return { diff1, diff2 };
    }
};
// @lc code=end
