#pragma once
#include "TCandidate.h"

class TCandidate_Zad1 : public TCandidate
{
public:
    TCandidate* create() override { return new TCandidate_Zad1(); }
    TCandidate* create_copy() const override { return new TCandidate_Zad1(*this); }
    TCandidate_Zad1() : TCandidate()
    {
        init_vector(); 
    }

    TCandidate_Zad1(const TCandidate_Zad1& original) : TCandidate(original) {}

    void rate() override
    {
        double x1 = genotype[0].get_val(); 
        double x2 = genotype[1].get_val();
        mark = 2 * (x1 + x2);              
    }

protected:
    void init_vector() override
    {
        genotype.push_back(TParam("x1", 0, 100, 1)); 
        genotype.push_back(TParam("x2", 0, 10, 1));  
        gens_count = (int)genotype.size();           
    }
};