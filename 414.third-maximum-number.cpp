/*
 * @lc app=leetcode id=414 lang=cpp
 *
 * [414] Third Maximum Number
 */

// @lc code=start
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int, less<>> s;
        for (const auto &el : nums) {
            if (auto pos = s.find(el); pos != s.cend()) continue;
            if (s.size() < 3) { s.insert(el); continue; }
            if (el < *s.cbegin()) continue;
            s.erase(s.begin()); s.insert(el);
        }
        return (s.size() >= 3) ? *s.cbegin() : *s.crbegin();
    }
};
// @lc code=end
