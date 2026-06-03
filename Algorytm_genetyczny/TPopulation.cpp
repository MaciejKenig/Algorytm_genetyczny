#include <iostream>
#include <algorithm>
#include "TPopulation.h"

using namespace std;

unsigned int TPopulation::population_count = 0;


TPopulation::TPopulation(unsigned int cands_count, TCandidate* pattern)
{
    _id = population_count;
    population_count++;
    candidate_count = cands_count;
    best_val = 0;

    for (unsigned int i = 0; i < cands_count; i++)
    {
        
        candidates.push_back(pattern->create());
    }
}

TPopulation::TPopulation(const TPopulation& original)
{
    _id = population_count;
    population_count++;
    candidate_count = original.get_candidates_count();
    best_val = original.get_best_val();

    for (unsigned int i = 0; i < candidate_count; i++)
    {
        const TCandidate* wsk_os_org = original.get_candidate_wsk(i);
        
        candidates.push_back(wsk_os_org->create_copy());
    }
}


TPopulation::~TPopulation()
{
    for (size_t i = 0; i < candidates.size(); i++)
    {
        delete candidates[i];
    }
}


const TCandidate* TPopulation::get_candidate_wsk(int id) const
{
    return candidates[id];
}


void TPopulation::calculate()
{
    
    for (size_t i = 0; i < candidates.size(); i++)
    {
        candidates[i]->rate();
    }

 
    if (!candidates.empty())
    {
        best_val = candidates[0]->get_mark();
        for (size_t i = 1; i < candidates.size(); i++)
        {
            if (candidates[i]->get_mark() > best_val)
            {
                best_val = candidates[i]->get_mark();
            }
        }
    }
}


void TPopulation::info()
{
    
    cout << "===== POPULATION #" << _id << " =====" << endl;

    
    for (size_t i = 0; i < candidates.size(); i++)
    {
        cout << "candidate#" << i << ": " << candidates[i]->get_mark() << endl;
    }

    cout << "best val: " << best_val << endl; 
}


TCandidate* TPopulation::get_best_candidate()
{
    if (candidates.empty()) return nullptr;

    size_t best_index = 0;
    double max_mark = candidates[0]->get_mark();

    for (size_t i = 1; i < candidates.size(); i++)
    {
        if (candidates[i]->get_mark() > max_mark)
        {
            max_mark = candidates[i]->get_mark();
            best_index = i;
        }
    }
    return candidates[best_index]; 
}