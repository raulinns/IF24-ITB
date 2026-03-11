#pragma once
#include "Vehicle.hpp"

using namespace std;

class AirVehicle: protected Vehicle {
protected:
    int maxAltitude;

public:
    AirVehicle(string vehicleId, string brand, int maxSpeed, int maxAltitude);
    ~AirVehicle();

    void fly(string) const;
    string showSpec() const;
    string getBrandName() const;
};


