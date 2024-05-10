/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start

#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> set1{nums1.begin(), nums1.end()}, set2{nums2.begin(), nums2.end()};
        vector<int> ret;
        set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(ret));
        return ret;
    }
};
// @lc code=end
