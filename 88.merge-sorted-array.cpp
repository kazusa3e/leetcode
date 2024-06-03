/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> n1 = nums1, n2 = nums2;
        n1.resize(m); n2.resize(n);
        auto iter = nums1.begin(),
            left_iter = n1.begin(),
            right_iter = n2.begin();
        while (left_iter != n1.end() && right_iter != n2.end()) {
            if (*left_iter < *right_iter) {
                *iter = *left_iter;
                iter += 1; left_iter += 1;
            } else {
                *iter = *right_iter;
                iter += 1; right_iter += 1;
            }
        }
        while (left_iter != n1.end()) {
            *iter = *left_iter;
            iter += 1; left_iter += 1;
        }
        while (right_iter != n2.end()) {
            *iter = *right_iter;
            iter += 1; right_iter += 1;
        }
    }
};
// @lc code=end
