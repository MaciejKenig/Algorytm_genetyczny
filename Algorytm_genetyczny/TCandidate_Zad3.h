#pragma once
#include "TCandidate.h"

class TCandidate_Zad3 : public TCandidate
{
public:
    TCandidate* create() override { return new TCandidate_Zad3(); }
    TCandidate* create_copy() const override { return new TCandidate_Zad3(*this); }
    TCandidate_Zad3() : TCandidate()
    {
        init_vector();
        rand_gens_val();
    }

    TCandidate_Zad3(const TCandidate_Zad3& original) : TCandidate(original) {}

    void rate() override // 
    {
        double x1 = genotype[0].get_val();
        double x2 = genotype[1].get_val();
        double x3 = genotype[2].get_val(); 

        mark = 100 * x1 + 10 * x2 + x3;
    }

protected:
    void init_vector() override  
    {
        genotype.push_back(TParam("x1", 0, 10, 1));
        genotype.push_back(TParam("x2", 0, 10, 1));
        genotype.push_back(TParam("x3", 0, 10, 1)); 
        gens_count = (int)genotype.size();          
    }
};