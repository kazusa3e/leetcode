/*
 * @lc app=leetcode id=1346 lang=cpp
 *
 * [1346] Check If N and Its Double Exist
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (auto iter = arr.begin(); iter != arr.end(); ++iter) {
            auto pos = (*iter >= 0)
                ? lower_bound(iter + 1, arr.end(), *iter * 2)
                : lower_bound(arr.begin(), iter, *iter * 2);
            if (pos == arr.end()) continue;
            if (*iter * 2 == *pos && iter != pos) return true;
        }
        return false;
    }
};
// @lc code=end
