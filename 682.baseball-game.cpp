/*
 * @lc app=leetcode id=682 lang=cpp
 *
 * [682] Baseball Game
 */

// @lc code=start

#include <vector>
#include <deque>
#include <numeric>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        deque<int> scores;
        for (const auto &oper : operations) {
            if (oper == "+") {
                scores.push_back(scores[scores.size() - 1] + scores[scores.size() - 2]);
            } else if (oper == "D") {
                scores.push_back(scores.back() * 2);
            } else if (oper == "C") {
                scores.pop_back();
            } else {
                scores.push_back(stoi(oper));
            }
        }
        return accumulate(scores.begin(), scores.end(), 0);
    }
};
// @lc code=end
