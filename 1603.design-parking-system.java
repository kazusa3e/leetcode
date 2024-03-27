/*
 * @lc app=leetcode id=1603 lang=java
 *
 * [1603] Design Parking System
 */

// @lc code=start
class ParkingSystem {

    private int numOfBig;
    private int numOfMedium;
    private int numOfSmall;

    public ParkingSystem(int big, int medium, int small) {
        this.numOfBig = big;
        this.numOfMedium = medium;
        this.numOfSmall = small;
    }
    
    public boolean addCar(int carType) {
        if (carType == 1 && this.numOfBig != 0) {
            this.numOfBig -= 1;
            return true;
        }
        if (carType == 2 && this.numOfMedium != 0) {
            this.numOfMedium -= 1;
            return true;
        }
        if (carType == 3 && this.numOfSmall != 0) {
            this.numOfSmall -= 1;
            return true;
        }
        return false;
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */
// @lc code=end
