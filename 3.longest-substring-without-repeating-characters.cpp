/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start

#include <algorithm>
#include <set>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        unordered_map<char, unsigned> win;
        int left = 0, right = 0;
        int longest_sz = 0;
        while (right != s.size()) {
            right += 1;
            win[s[right - 1]] += 1;
            while (any_of(win.begin(), win.end(), [](const auto &kv) { return kv.second > 1; })) {
                win[s[left]] -= 1;
                left += 1;
            }
            longest_sz = max(longest_sz, right - left);
        }
        return longest_sz;
    }
};
// @lc code=end
