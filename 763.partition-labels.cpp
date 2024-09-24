/*
 * @lc app=leetcode id=763 lang=cpp
 *
 * [763] Partition Labels
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_position(26, -1);
        for (int ix = 0; ix != s.size(); ++ix) {
            last_position[s[ix] - 'a'] = ix;
        }
        vector<int> ret;
        int start = 0, end = 0;
        for (int ix = 0; ix != s.size(); ++ix) {
            end = max(last_position[s[ix] - 'a'], end);
            if (end == ix) {
                ret.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ret;
    }
};
// @lc code=end
