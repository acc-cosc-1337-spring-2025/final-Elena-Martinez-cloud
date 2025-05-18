//shooter.cpp
#include "shooter.h"
#include <iostream>
using std::cout;

Roll* Shooter::throw_dice(Die& d1, Die& d2) {
    Roll* roll = new Roll(d1, d2);
    roll -> roll_dice();
    rolls.push_back(roll);
    return roll;
}

void Shooter::display_rolled_values() const {
    for (const Roll* roll : rolls) {
        cout << "Rolled Value: " << roll -> roll_value();
    }
}

Shooter::~Shooter() {
    for (Roll* roll : rolls) {
        delete roll;
    }
    rolls.clear();
}