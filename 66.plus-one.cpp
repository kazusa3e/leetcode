/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (auto iter = digits.rbegin(); iter != digits.rend(); ++iter) {
            int tmp = ((carry) ? 1 : 0) + *iter;
            carry = false;
            if (tmp == 10) {
                *iter = 0; carry = true;
            } else {
                *iter = tmp;
            }
        }
        if (carry) digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end
