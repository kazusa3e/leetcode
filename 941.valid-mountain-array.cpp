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
        enum class STATE {INCREASING, DECREASING};
        STATE state = STATE::INCREASING;
        for (int ix = 1; ix != arr.size(); ++ix) {
            if (state == STATE::INCREASING) {
                if (arr[ix] > arr[ix - 1]) continue;
                else if (arr[ix] < arr[ix - 1]) {
                    if (ix == 1) return false;
                    state = STATE::DECREASING;
                } else {
                    return false;
                }
            } else {
                if (arr[ix] < arr[ix - 1]) continue;
                else return false;
            }
        }
        return (state == STATE::DECREASING);
    }
};
// @lc code=end
