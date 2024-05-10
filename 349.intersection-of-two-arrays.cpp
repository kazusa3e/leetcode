/*
 * @lc app=leetcode id=349 lang=cpp
 *
 * [349] Intersection of Two Arrays
 */

// @lc code=start

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1{nums1.begin(), nums1.end()}, set2{nums2.begin(), nums2.end()};
        vector<int> ret;
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(ret));
        return ret;
    }
};
// @lc code=end
