/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        auto is_vowel = [](const char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
                || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
        };
        auto left = s.begin(), right = prev(s.end());
        while (left < right) {
            if (!is_vowel(*left)) {
                left += 1; continue;
            }
            if (!is_vowel(*right)) {
                right -= 1; continue;
            }
            swap(*left, *right);
            left += 1; right -= 1;
        }
        return s;
    }
};
// @lc code=end
