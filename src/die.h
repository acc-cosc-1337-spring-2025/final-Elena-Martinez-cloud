//die.h
#ifndef DIE_H
#define DIE_H

#include <cstdlib>
#include <ctime>

class die {
public: 
    int roll ();

private:
    int sides{6};

};

#endif