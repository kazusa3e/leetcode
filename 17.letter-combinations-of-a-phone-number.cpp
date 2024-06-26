/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

// @lc code=start

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
private:
    unordered_map<char, vector<char>> keymappings = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}},
    };

    string digits_;
    vector<string> results_;
    vector<char> bag_;

    void backtracking(string::iterator begin) {
        if (begin == digits_.end()) {
            if (bag_.size() == digits_.size()) {
                results_.push_back(string {bag_.begin(), bag_.end()});
            }
            return;
        }
        for (auto iter = begin; iter != digits_.end(); ++iter) {
            for (auto ch : keymappings[*iter]) {
                bag_.push_back(ch);
                backtracking(iter + 1);
                bag_.pop_back();
            }
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        digits_ = digits;
        backtracking(digits_.begin());
        return results_;
    }

};
// @lc code=end
