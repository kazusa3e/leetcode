/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<>> pq;
        unordered_set<int> seen;
        for (const auto &el : nums) {
            if (auto pos = seen.find(el); pos != seen.end()) continue;
            pq.push(el); seen.insert(el);
            if (pq.size() > 3) pq.pop();
        }
        if (pq.size() >= 3) return pq.top();
        while (pq.size() != 1) pq.pop();
        return pq.top();
    }
};
// @lc code=end
