/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        set<int> seen;
        for (const auto &el : arr) {
            if (auto pos = seen.find(el); pos != seen.end()) return true;
            seen.insert(el * 2);
            if (el % 2 == 0) seen.insert(el / 2);
        }
        return false;
    }
};
// @lc code=end
