/*
 * @lc app=leetcode id=344 lang=cpp
 *
 * [344] Reverse String
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        reverse(s.begin(), s.end());
    }
};
// @lc code=end
