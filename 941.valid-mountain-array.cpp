/*
 * @lc app=leetcode id=941 lang=cpp
 *
 * [941] Valid Mountain Array
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;
        int left = 0, right = arr.size() - 1;
        while (left + 1 != arr.size() && arr[left + 1] > arr[left]) left += 1;
        while (right - 1 != 0 && arr[right - 1] > arr[right]) right -= 1;
        if (left == 0 || right == arr.size() - 1) return false;
        return (left == right);
    }
};
// @lc code=end
