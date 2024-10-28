/*
 * @lc app=leetcode id=1306 lang=cpp
 *
 * [1306] Jump Game III
 */

// @lc code=start

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false); visited[start] = true;
        queue<int> qu; qu.push(start);
        while (!qu.empty()) {
            auto curr = qu.front(); qu.pop();
            if (curr - arr[curr] >= 0 && !visited[curr - arr[curr]]) {
                qu.push(curr - arr[curr]); visited[curr - arr[curr]] = true;
            }
            if (curr + arr[curr] < arr.size() && !visited[curr + arr[curr]]) {
                qu.push(curr + arr[curr]); visited[curr + arr[curr]] = true;
            }
        }
        for (unsigned ix = 0; ix != arr.size(); ++ix) {
            if (arr[ix] == 0 && visited[ix]) return true;
        }
        return false;
    }
};
// @lc code=end
