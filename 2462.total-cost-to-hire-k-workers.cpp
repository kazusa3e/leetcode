/*
 * @lc app=leetcode id=2462 lang=cpp
 *
 * [2462] Total Cost to Hire K Workers
 */

// @lc code=start

#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
#include <deque>
#include <limits>

using namespace std;

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans = 0;
        deque<int> de { costs.begin(), costs.end() };
        priority_queue<int, vector<int>, greater<int>> pq_left, pq_right;
        while (k != 0) {
            while (!de.empty() && pq_left.size() != candidates) {
                pq_left.push(de.front()); de.pop_front();
            }
            while (!de.empty() && pq_right.size() != candidates) {
                pq_right.push(de.back()); de.pop_back();
            }
            auto t1 = (pq_left.empty()) ? numeric_limits<int>::max() : pq_left.top(),
                t2 = (pq_right.empty()) ? numeric_limits<int>::max() : pq_right.top();
            if (t1 <= t2) {
                ans += t1; pq_left.pop();
            } else {
                ans += t2; pq_right.pop();
            }
            k -= 1;
        }
        return ans;
    }
};
// @lc code=end
