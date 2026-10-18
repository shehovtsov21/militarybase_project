#include "Bus.h"
#include "Base.h"
#include <stdexcept>
using namespace std;

Bus::Bus(int passengers, int capacity, double petrol, double max_petrol)
    : Vehicle(petrol, max_petrol), people(passengers), max_people(capacity) {
    if (capacity < 0 || passengers < 0 || passengers > capacity)
        throw invalid_argument("Invalid passenger count or capacity");
}

int Bus::getPeopleCount() const { return people; }

int Bus::getMaxPeople() const { return max_people; }

void Bus::arrive() {
    if (on_base) return;

    Vehicle::arrive();
    Base::people_on_base += people;
    people = 0;
}

bool Bus::leave() {
    // Базовый метод заправляет машину и забирает водителя.
    if (!Vehicle::leave()) return false;

    people = max_people;
    if (Base::people_on_base < people)
        people = Base::people_on_base;

    Base::people_on_base -= people;
    return true;
}
