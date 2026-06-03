#pragma once
#include <vector>
#include "TCandidate.h"

class TPopulation
{
    static unsigned int population_count;
    unsigned int _id;
    unsigned int candidate_count;
    std::vector<TCandidate*> candidates;
    double best_val = 0;

public:
    TPopulation(unsigned int cands_count, TCandidate* pattern);
    TPopulation(const TPopulation& original);
    ~TPopulation();
    TCandidate* promote_candidate();

    void calculate();
    unsigned int get_id() { return _id; }
    unsigned int get_candidates_count() const { return candidate_count; }
    double get_best_val() const { return best_val; }
    void info();
    const TCandidate* get_candidate_wsk(int id) const;
    TCandidate* get_best_candidate();
};