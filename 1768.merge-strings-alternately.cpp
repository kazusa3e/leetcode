/*
 * @lc app=leetcode id=1768 lang=cpp
 *
 * [1768] Merge Strings Alternately
 */

// @lc code=start

#include <string>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ret(word1.size() + word2.size(), 0);
        auto dst = ret.begin();
        auto iter1 = word1.cbegin(), iter2 = word2.cbegin();
        while (iter1 != word1.cend() && iter2 != word2.cend()) {
            *(dst++) = *(iter1++);
            *(dst++) = *(iter2++);
        }
        while (iter1 != word1.cend()) *(dst++) = *(iter1++);
        while (iter2 != word2.cend()) *(dst++) = *(iter2++);
        return ret;
    }
};
// @lc code=end
