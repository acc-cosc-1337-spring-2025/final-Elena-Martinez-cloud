//die.cpp
#include "die.h"



int Die::roll() {

    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }

    return (rand() % sides) + 1;
}