/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 */

// @lc code=start

#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path; path.push_back(0);
        function<void(const int, const int)> dfs = [&](const int from, const int to) -> void {
            if (from == to) {
                paths.push_back(path); return;
            }
            for_each(graph[from].begin(), graph[from].end(), [&](const int n) {
                path.push_back(n);
                dfs(n, to);
                path.pop_back();
            });
        };
        dfs(0, graph.size() - 1);
        return paths;
    }
};
// @lc code=end
