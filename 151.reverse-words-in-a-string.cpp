/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stringstream tokenizer(s);
        vector<string> tokens;
        tokens.insert(tokens.begin(), istream_iterator<string>(tokenizer), istream_iterator<string>());
        reverse(tokens.begin(), tokens.end());
        ostringstream oss;
        for (auto iter = tokens.begin(); iter != tokens.end(); ++iter) {
            if (next(iter) == tokens.end()) {
                oss << *iter;
            } else {
                oss << *iter << " ";
            }
        }
        return oss.str();
    }
};
// @lc code=end
