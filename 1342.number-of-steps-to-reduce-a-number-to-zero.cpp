/*
 * @lc app=leetcode id=1342 lang=cpp
 *
 * [1342] Number of Steps to Reduce a Number to Zero
 */

// @lc code=start
class Solution {
public:
    int numberOfSteps(int num) {
        unsigned num_steps = 0;
        while (num != 0) {
            (num % 2 == 0) ? num /= 2 : num -= 1;
            ++num_steps;
        }
        return num_steps;
    }
};
// @lc code=end
