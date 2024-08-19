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
    if (m == 0 && n == 0) return;
    auto iter = nums1.end() - 1;
    int i1 = m - 1, i2 = n - 1;
    while (i1 >= 0 && i2 >= 0) {
      if (nums1[i1] > nums2[i2]) {
        *iter = nums1[i1]; iter -= 1; i1 -= 1;
      } else {
        *iter = nums2[i2]; iter -= 1; i2 -= 1;
      }
    }
    while (i1 >= 0) {
      *iter = nums1[i1]; iter -= 1; i1 -= 1;
    }
    while (i2 >= 0) {
      *iter = nums2[i2]; iter -= 1; i2 -= 1;
    }
  }
};
// @lc code=end
