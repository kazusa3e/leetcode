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
        string ret(word1.size() + word2.size(), '\0');
        bool turn = false;
        unsigned sz = 0, idx1 = 0, idx2 = 0;
        while (idx1 != word1.size() && idx2 != word2.size()) {
            if (!turn) {
                ret[sz++] = word1[idx1++];
            } else {
                ret[sz++] = word2[idx2++];
            }
            turn = !turn;
        }
        while (idx1 != word1.size()) {
            ret[sz++] = word1[idx1++];
        }
        while (idx2 != word2.size()) {
            ret[sz++] = word2[idx2++];
        }
        return ret;
    }
};
// @lc code=end
