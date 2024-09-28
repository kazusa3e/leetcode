/*
 * @lc app=leetcode id=1502 lang=cpp
 *
 * [1502] Can Make Arithmetic Progression From Sequence
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() <= 2) return true;
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];
        for (auto iter = arr.begin() + 2; iter != arr.end(); ++iter) {
            if (*iter - *(iter - 1) != diff) return false;
        }
        return true;
    }
};
// @lc code=end
