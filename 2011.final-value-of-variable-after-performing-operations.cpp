/*
 * @lc app=leetcode id=2011 lang=cpp
 *
 * [2011] Final Value of Variable After Performing Operations
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:

    bool is_increment(const string &op) const {
        for (const auto ch : op) {
            if (ch == '-') return false;
            if (ch == '+') return true;
        }
        return {};
    }

    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0;
        for (const auto &el : operations) {
            (is_increment(el)) ? ++val : --val;
        }
        return val;
    }
};
// @lc code=end
