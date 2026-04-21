#include "WaterVehicle.hpp"

WaterVehicle::WaterVehicle(string vehicleId, string brand, int maxSpeed,
                           int displacement)
    : Vehicle(vehicleId, brand, maxSpeed), displacement(displacement) {

    cout << "[CREATE] WaterVehicle " << brand << " with " << displacement
         << " tons displacement ready" << endl;
}

WaterVehicle::~WaterVehicle() {
    cout << "[DELETE] WaterVehicle " << brand << " destroyed" << endl;
}

void WaterVehicle::sail(string dest) const {
    cout << "[SAIL] " << brand << " (" << displacement << " tons) sailing to "
         << dest << endl;
}

string WaterVehicle::showSpec() const { return getSpec(); }
