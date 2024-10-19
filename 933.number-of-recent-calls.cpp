/*
 * @lc app=leetcode id=933 lang=cpp
 *
 * [933] Number of Recent Calls
 */

// @lc code=start

#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class RecentCounter {
public:
    RecentCounter() { }
    
    int ping(int t) {
        timestamps.push(t);
        while (!timestamps.empty() && timestamps.front() < t - 3000) {
            timestamps.pop();
        }
        return timestamps.size();
    }

private:
    queue<int> timestamps;
};
/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
