#include <iostream>

using namespace std;

// 1603. Design Parking System

class ParkingSystem {
    int parkingSpaces[3];
    public:
        ParkingSystem(int big, int medium, int small) {
            parkingSpaces[0] = big;
            parkingSpaces[1] = medium;
            parkingSpaces[2] = small;
        }
        
        bool addCar(int carType) {
            if (parkingSpaces[carType - 1] != 0 ) {
                parkingSpaces[carType - 1] -= 1;
                return true;
            }

            return false;
        }
};
    
/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main() {
    ParkingSystem parkingsystem;
}