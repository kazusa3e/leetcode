/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (all_of(nums.begin(), nums.end(), [](int n) {
            return n == 0;
        })) {
            return "0";
        }
        vector<string> s;
        transform(nums.begin(), nums.end(), back_inserter(s), [](int s) {
            return to_string(s);
        });
        sort(s.begin(), s.end(), [](const string &a, const string &b) {
            return stoull(a + b) > stoull(b + a);
        });
        ostringstream oss;
        for (auto elem : s) {
            oss << elem;
        }
        return oss.str();
    }
};
// @lc code=end
