#pragma once

#include "Vehicle.h"

class Bus : public Vehicle {
    int people;
    int max_people;

public:
    Bus(int passengers, int capacity, double petrol, double max_petrol);
    int getPeopleCount() const;
    int getMaxPeople() const;
    void arrive() override;
    bool leave() override;
};
