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
public:

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

    vector<string> results;
    vector<char> bag;

    vector<string> letterCombinations(string digits) {
        if (digits == "") return {};
        backtracking(digits);
        return results;
    }

    void backtracking(string digits) {
        if (digits == "") {
            results.push_back({bag.begin(), bag.end()});
            return;
        }
        auto letters = keymappings[digits[0]];
        for (auto ch : letters) {
            bag.push_back(ch);
            backtracking({digits.begin() + 1, digits.end()});
            bag.pop_back();
        }
    }
};
// @lc code=end
