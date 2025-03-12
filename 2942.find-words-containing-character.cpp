/*
 * @lc app=leetcode id=2942 lang=cpp
 *
 * [2942] Find Words Containing Character
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ret;
        for (auto ix = 0ull; ix != words.size(); ++ix) {
            const auto pos = find(words[ix].cbegin(), words[ix].cend(), x);
            if (pos != words[ix].cend()) ret.push_back(ix);
        }
        return ret;
    }
};
// @lc code=end
