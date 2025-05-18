//point_phase.cpp
#include "point_phase.h"

PointPhase::PointPhase(int p) : point(p) {}

RollOutcome PointPhase::get_outcome(Roll* roll){
    int value = roll->roll_value();
    if (value == point) return RollOutcome::point;
    if (value == 7) return RollOutcome::seven_out;
    return RollOutcome::nopoint;
}