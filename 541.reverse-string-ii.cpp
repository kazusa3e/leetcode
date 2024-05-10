/*
 * @lc app=leetcode id=541 lang=cpp
 *
 * [541] Reverse String II
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (auto iter = s.begin(); iter < s.end(); iter += 2 * k) {
            auto end = (iter + k > s.end()) ? s.end() : iter + k;
            reverse(iter, end);
        }
        return s;
    }
};
// @lc code=end
