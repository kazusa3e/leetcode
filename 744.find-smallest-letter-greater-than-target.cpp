/*
 * @lc app=leetcode id=744 lang=cpp
 *
 * [744] Find Smallest Letter Greater Than Target
 */

// @lc code=start

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto pos = upper_bound(letters.begin(), letters.end(), target);
        return (pos == letters.end()) ? letters.front() : *pos;
    }
};
// @lc code=end
