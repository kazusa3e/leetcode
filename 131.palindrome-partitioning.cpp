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
    vector<vector<string>> results_;
    vector<string> bag_;
    string s_;

    void backtracking(string::iterator pos) {
        if (pos == s_.end()) {
            results_.push_back(bag_);
            return;
        }
        for (auto iter = pos + 1; iter <= s_.end(); ++iter) {
            if (!isPalindrome(pos, iter)) continue;
            bag_.push_back({pos, iter});
            backtracking(iter);
            bag_.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        s_ = s;
        backtracking(s_.begin());
        return results_;
    }
};
// @lc code=end
