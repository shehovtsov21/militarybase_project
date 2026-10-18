#include "Base.h"
#include <iostream>
using namespace std;

int Base::people_on_base = 20;
int Base::vehicles_on_base = 0;
double Base::petrol_on_base = 500;
double Base::goods_on_base = 30;

void Base::show() {
    cout << "People: " << people_on_base << '\n';
    cout << "Vehicles: " << vehicles_on_base << '\n';
    cout << "Petrol: " << petrol_on_base << " litres\n";
    cout << "Goods: " << goods_on_base << " tons\n\n";
}
