/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool isPalindrome(const string::iterator &begin, const string::iterator &end) {
    return equal(begin, begin + (end - begin) / 2, reverse_iterator(end));
}

class Solution {
private:
    string s_;
    vector<string> bag_;
    vector<vector<string>> results_;
    void backtracking(string::iterator left, string::iterator right) {
        if (left == s_.end()) {
            results_.push_back(bag_);
            return;
        }
        for (auto iter = right; iter <= s_.end(); ++iter) {
            if (isPalindrome(left, iter)) {
                bag_.push_back(string {left, iter});
                backtracking(iter, iter + 1);
                bag_.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        s_ = s;
        backtracking(s_.begin(), s_.begin() + 1);
        return results_;
    }
};
// @lc code=end
