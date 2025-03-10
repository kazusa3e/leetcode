/*
 * @lc app=leetcode id=1299 lang=cpp
 *
 * [1299] Replace Elements with Greatest Element on Right Side
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        auto m_max = arr.back(); arr.back() = -1;
        if (arr.size() == 1) return arr;
        for (auto iter = arr.rbegin() + 1; iter != arr.rend(); ++iter) {
            auto tmp = *iter; *iter = m_max; m_max = max(m_max, tmp);
        }
        return arr;
    }
};
// @lc code=end
