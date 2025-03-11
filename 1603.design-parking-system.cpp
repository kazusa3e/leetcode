/*
 * @lc app=leetcode id=1603 lang=cpp
 *
 * [1603] Design Parking System
 */

// @lc code=start
#include <array>

using namespace std;

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        capability[1] = big; capability[2] = medium; capability[3] = small;
    }
    
    bool addCar(int carType) {
        if (capability[carType] == 0) return false;
        --capability[carType];
        return true;
    }
private:
    array<int, 4> capability;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
