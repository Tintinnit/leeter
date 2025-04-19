#include <iostream>
#include <array>

using namespace std;

// 1603. Design Parking System

class ParkingSystem {
    const int BIG = 0;
    const int MEDIUM = 1;
    const int SMALL = 2;

    array<int, 3> parkingSpaces;

public:
    ParkingSystem(int big, int medium, int small) {
        parkingSpaces[BIG] = big;
        parkingSpaces[MEDIUM] = medium;
        parkingSpaces[SMALL] = small;
    }

    bool addCar(int carType) {
        // Check if carType is valid (1 to 3)
        if (carType < 1 || carType > 3) return false;

        int index = carType - 1;
        if (parkingSpaces[index] > 0) {
            parkingSpaces[index]--;
            return true;
        }

        return false;
    }
};

int main() {
    ParkingSystem parkingSystem(1, 1, 0);
    cout << boolalpha;  // Print bools as true/false instead of 1/0

    cout << parkingSystem.addCar(1) << endl; // true
    cout << parkingSystem.addCar(2) << endl; // true
    cout << parkingSystem.addCar(3) << endl; // false
    cout << parkingSystem.addCar(1) << endl; // false
}
