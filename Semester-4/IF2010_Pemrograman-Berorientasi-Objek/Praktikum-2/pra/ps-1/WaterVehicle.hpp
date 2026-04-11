#pragma once
#include "Vehicle.hpp"

class WaterVehicle : protected Vehicle {
  protected:
    int displacement;

  public:
    WaterVehicle(string vehicleId, string brand, int maxSpeed, int displacement);
    ~WaterVehicle();

    void sail(string) const;

    string showSpec() const;
};
