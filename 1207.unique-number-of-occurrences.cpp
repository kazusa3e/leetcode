/*
 * @lc app=leetcode id=1207 lang=cpp
 *
 * [1207] Unique Number of Occurrences
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, unsigned> occurrences;   // val -> occurrences
        for (auto el : arr) occurrences[el] += 1;
        unordered_set<unsigned> seen;
        for (auto kv : occurrences) {
            if (auto pos = seen.find(kv.second); pos != seen.end()) {
                return false;
            }
            seen.insert(kv.second);
        }
        return true;
    }
};
// @lc code=end
