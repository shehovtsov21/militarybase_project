#include "Truck.h"
#include "Base.h"
#include <stdexcept>
using namespace std;

Truck::Truck(double cargo, double capacity, double petrol, double max_petrol)
    : Vehicle(petrol, max_petrol), load(cargo), max_load(capacity) {
    if (capacity < 0 || cargo < 0 || cargo > capacity)
        throw invalid_argument("Invalid cargo amount or capacity");
}

double Truck::getCurrentLoad() const { return load; }

double Truck::getMaxLoad() const { return max_load; }

void Truck::arrive() {
    if (on_base) return;

    Vehicle::arrive();
    Base::goods_on_base += load;
    load = 0;
}

bool Truck::leave() {
    if (!Vehicle::leave()) return false;

    load = max_load;
    if (Base::goods_on_base < load)
        load = Base::goods_on_base;

    Base::goods_on_base -= load;
    return true;
}
