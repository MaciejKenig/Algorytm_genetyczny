#pragma once
#include "TCandidate.h"
#include <vector>

class TPopulation
{
private:
    static unsigned int         pop_count;
    unsigned int                _id;
    unsigned int                candidated_count;
    std::vector<TCandidate>     candidates;
    double                      best_val = 0;

    const TCandidate* get_candidate_wsk(int _id) const;

public:
    TPopulation(unsigned int cands_count);
    TPopulation();
    TPopulation(const TPopulation& original);
    TCandidate get_best_candidate();
    void calculate(); 
    void info();      

    unsigned int get_id() const { return _id; }
    unsigned int get_candidates_count() const { return candidated_count; }
    double get_best_val() const { return best_val; }
};