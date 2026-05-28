#pragma once
#include "TParam.h"

#define GENS_COUNT 2

class TCandidate
{
    TParam genotype[GENS_COUNT] =
    {
            TParam("x1", 0, 10, 1),
            TParam("x2", 0, 10, 1)
    };

    double mark;

private:
    void rand_gens_val();

public:
    TCandidate(double initial_rate);
    TCandidate();
    TCandidate(const TCandidate& oryginal); 

    double get_mark() { return mark; };

    void rate();
    void info();
};