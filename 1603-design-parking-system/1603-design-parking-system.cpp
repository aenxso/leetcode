class ParkingSystem {
public:
    vector<int> stalls;
    ParkingSystem(int big, int medium, int small) {
        stalls = {big, medium, small};
    }
    
    bool addCar(int carType) {
        if(stalls[carType - 1]) {
            stalls[carType - 1] -= 1;
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