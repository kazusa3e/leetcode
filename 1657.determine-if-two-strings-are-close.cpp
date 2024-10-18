/*
 * @lc app=leetcode id=1657 lang=cpp
 *
 * [1657] Determine if Two Strings Are Close
 */

// @lc code=start

#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if (word1.size() != word2.size()) return false;
        vector<unsigned> his1(26, 0),
            his2(26, 0);
        vector<bool> alphabet1(26, false),
            alphabet2(26, false);
        for_each(word1.begin(), word1.end(), [&his1, &alphabet1](char ch) {
            his1[ch - 'a'] += 1;
            alphabet1[ch - 'a'] = true;
        });
        for_each(word2.begin(), word2.end(), [&his2, &alphabet2](char ch) {
            his2[ch - 'a'] += 1;
            alphabet2[ch - 'a'] = true;
        });
        sort(his1.begin(), his1.end());
        sort(his2.begin(), his2.end());
        return his1 == his2 && alphabet1 == alphabet2;
    }
};
// @lc code=end
