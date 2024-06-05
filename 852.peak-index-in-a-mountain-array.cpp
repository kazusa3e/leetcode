/*
 * @lc app=leetcode id=852 lang=cpp
 *
 * [852] Peak Index in a Mountain Array
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
            if (arr[mid - 1] > arr[mid]) right = mid;
            if (arr[mid + 1] > arr[mid]) left = mid;
        }
        return left;
    }
};
// @lc code=end
