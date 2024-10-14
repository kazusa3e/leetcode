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
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        stringstream tokenizer {s};
        tokens.insert(tokens.begin(), istream_iterator<string> {tokenizer}, istream_iterator<string> {});
        reverse(tokens.begin(), tokens.end());
        ostringstream oss;
        copy(tokens.begin(), tokens.end(), ostream_iterator<string>(oss, " "));
        string ret = oss.str();
        ret.pop_back();
        return ret;
    }
};
// @lc code=end
