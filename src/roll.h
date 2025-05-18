//roll.h
#ifndef ROLL_H
#define ROLL_H

#include "die.h"

class Die;

class Roll
{
private:
    Die& die1;
    Die& die2;
    int rolled_value{0};

public:
    Roll(Die& d1, Die& d2);
    void roll_dice();
    int roll_value() const;
};

#endif