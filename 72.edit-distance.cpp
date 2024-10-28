/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start

#include <string>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, numeric_limits<int>::max()));

        for (unsigned i = 0; i != word1.size() + 1; ++i) dp[i][0] = i;
        for (unsigned j = 0; j != word2.size() + 1; ++j) dp[0][j] = j;
        for (unsigned i = 1; i != word1.size() + 1; ++i) {
            for (unsigned j = 1; j != word2.size() + 1; ++j) {
                unsigned remove = dp[i - 1][j] + 1,
                    add = dp[i][j - 1] + 1,
                    replace = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                vector<unsigned> tmp = { remove, add, replace };
                dp[i][j] = *min_element(tmp.begin(), tmp.end());
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end
