/*
 * @lc app=leetcode id=1456 lang=cpp
 *
 * [1456] Maximum Number of Vowels in a Substring of Given Length
 */

// @lc code=start

#include <string>
#include <algorithm>

using namespace std;

bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

class Solution {
public:
    int maxVowels(string s, int k) {
        auto l = s.begin(), r = s.begin() + k;
        int win = count_if(l, r, [](char ch) { return is_vowel(ch); });
        int max_cnt = win;
        while (r != s.end()) {
            if (is_vowel(*l)) --win;
            if (is_vowel(*r)) ++win;
            ++l; ++r;
            max_cnt = max(max_cnt, win);
        }
        return max_cnt;
    }
};
// @lc code=end
