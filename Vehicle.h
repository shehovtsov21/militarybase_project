#pragma once

class Vehicle {
protected:
    double petrol_amount;
    double tank_volume;
    bool on_base;

public:
    Vehicle(double petrol, double tank);
    virtual ~Vehicle();

    double getTankVolume() const;
    double getPetrolAmount() const;
    virtual void arrive();
    virtual bool leave();
};
