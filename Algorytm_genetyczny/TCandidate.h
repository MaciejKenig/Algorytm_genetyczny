#pragma once
#include "TParam.h"

#define GENS_COUNT 2

class TCandidate
{
protected:
    TParam genotype[GENS_COUNT] =
    {
            TParam("x1", 0, 10, 1),
            TParam("x2", 0, 10, 1)
    };

    double mark;

protected:
    void rand_gens_val();
    double get_gen_val(int gen_id) const { return genotype[gen_id].get_val(); }

public:
    TCandidate(double initial_rate);
    TCandidate();
    TCandidate(const TCandidate& oryginal); 

    double get_mark() { return mark; };

    virtual void rate();
    void info();
};