#pragma once
#include "TCandidate.h"

class TCandidate_Zad2 : public TCandidate
{
public:
    TCandidate* create() override { return new TCandidate_Zad2(); }
    TCandidate* create_copy() const override { return new TCandidate_Zad2(*this); }
    TCandidate_Zad2() : TCandidate()
    {
        init_vector();   
        rand_gens_val(); 
    }

    TCandidate_Zad2(const TCandidate_Zad2& original) : TCandidate(original) {}

    void rate() override
    {
        
        double x1 = genotype[0].get_val(); 
        double x2 = genotype[1].get_val();
        mark = 100 * x1 + x2;             
    }

protected:
    void init_vector() override 
    {
        genotype.push_back(TParam("x1", 0, 10, 1));   
        genotype.push_back(TParam("x2", 11, 20, 2));  
        gens_count = (int)genotype.size();            
    }
};