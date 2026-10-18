#include "Vehicle.h"
#include "Base.h"
#include <stdexcept>
using namespace std;

Vehicle::Vehicle(double petrol, double tank)
    : petrol_amount(petrol), tank_volume(tank), on_base(false) {
    if (tank < 0 || petrol < 0 || petrol > tank)
        throw invalid_argument("Invalid fuel amount or tank volume");
}

Vehicle::~Vehicle() {}

double Vehicle::getTankVolume() const { return tank_volume; }

double Vehicle::getPetrolAmount() const { return petrol_amount; }

void Vehicle::arrive() {
    if (on_base) return;

    Base::vehicles_on_base++;
    Base::people_on_base++;  // Водитель выходит из машины.
    on_base = true;
    // Бензин остаётся в баке, на склад базы не добавляется.
}

bool Vehicle::leave() {
    double needed = tank_volume - petrol_amount;

    // Сначала проверяем все условия, затем меняем баланс.
    if (!on_base || Base::people_on_base < 1 ||
        Base::petrol_on_base < needed)
        return false;

    Base::petrol_on_base -= needed;
    petrol_amount = tank_volume;
    Base::people_on_base--;  // Один человек становится водителем.
    Base::vehicles_on_base--;
    on_base = false;
    return true;
}
