//come_out_phase.h
#ifndef COMEOUTPHASE_H
#define COMEOUTPHASE_H
#include "phase.h"

class ComeOutPhase : public Phase {
public:
    RollOutcome get_outcome(Roll* roll) override;
};

#endif