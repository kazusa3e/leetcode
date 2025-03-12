/*
 * @lc app=leetcode id=2469 lang=cpp
 *
 * [2469] Convert the Temperature
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        auto celsius2kelvin = [](double c) -> double { return c + 273.15; };
        auto celsius2fahrenheit = [](double c) -> double { return c * 1.80 + 32.00; };
        return { celsius2kelvin(celsius), celsius2fahrenheit(celsius) };
    }
};
// @lc code=end
