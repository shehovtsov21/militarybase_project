#include <iostream>
#include "Base.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Truck.h"
using namespace std;

int main() {
    Vehicle car(10, 50);
    Bus bus(5, 25, 20, 100);
    Truck truck(3, 10, 30, 150);

    // Через указатели Vehicle вызываются методы нужного класса.
    Vehicle* vehicles[] = { &car, &bus, &truck };

    cout << "Initial base balance:\n";
    Base::show();

    for (int i = 0; i < 3; i++)
        vehicles[i]->arrive();

    cout << "After arrival:\n";
    Base::show();

    for (int i = 0; i < 3; i++) {
        cout << "Vehicle " << i + 1 << ": ";
        if (vehicles[i]->leave())
            cout << "left the base\n";
        else
            cout << "cannot leave\n";
    }

    cout << "\nAfter departure:\n";
    Base::show();
    cout << "Bus passengers: " << bus.getPeopleCount() << '\n';
    cout << "Truck cargo: " << truck.getCurrentLoad() << " tons\n";
    return 0;
}
