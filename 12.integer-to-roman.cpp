/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ret;
        vector<pair<unsigned, string>> umap = {
            { 1000, "M" }, { 900, "CM" },
            { 500, "D" }, { 400, "CD" },
            { 100, "C" }, { 90, "XC" },
            { 50, "L" }, { 40, "XL" },
            { 10, "X" }, { 9, "IX" },
            { 5, "V" }, { 4, "IV" },
            { 1, "I" }
        };
        for (const auto &[bound, s] : umap) {
            while (num >= bound) {
                ret += s; num -= bound;
            }
        }
        return ret;
    }
};
