#pragma once

#include "Vehicle.h"

class Truck : public Vehicle {
    double load;
    double max_load;

public:
    Truck(double cargo, double capacity, double petrol, double max_petrol);
    double getCurrentLoad() const;
    double getMaxLoad() const;
    void arrive() override;
    bool leave() override;
};
