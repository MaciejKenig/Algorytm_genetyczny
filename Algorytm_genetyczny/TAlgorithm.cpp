#include <iostream>
#include "TAlgorithm.h"

using namespace std;

TAlgorithm::TAlgorithm(TCandidate* pattern, unsigned int candidates_count, unsigned int max_population_count, unsigned int min_improvment_proc)
{
    this->pattern = pattern; 
    stop_max_population_count = max_population_count; 
    stop_min_improvment_proc = min_improvment_proc;
    wsk_population_pres = new TPopulation{ candidates_count, pattern }; 
    wsk_population_prev = nullptr;
}

TAlgorithm::~TAlgorithm()
{
    delete wsk_population_pres;
    delete wsk_population_prev;
}

void TAlgorithm::run()
{
    bool stop = false; 
    while (!wsk_population_prev || !stop) 
    {
        wsk_population_pres->calculate(); 

        cout << "== Population #" << wsk_population_pres->get_id(); 
        cout << " || best val: " << wsk_population_pres->get_best_val() << endl; 

        stop = is_stop(); 

        if (!stop) 
        {
            unsigned int candidates_count = wsk_population_pres->get_candidates_count(); 

            delete wsk_population_prev; 
            wsk_population_prev = wsk_population_pres; 

      
            wsk_population_pres = new TPopulation{ candidates_count, pattern };
        }
    }
}

bool TAlgorithm::is_stop()
{
    return is_max_population() || is_min_improvment();
}

bool TAlgorithm::is_max_population()
{
    if (wsk_population_pres->get_id() >= stop_max_population_count) return true;
    return false;
}

bool TAlgorithm::is_min_improvment()
{
    if (!wsk_population_prev) return false;

    double prev = wsk_population_prev->get_best_val();
    double pres = wsk_population_pres->get_best_val();

    if (prev == 0) return false;

    double imp = ((pres - prev) / prev) * 100.0;
    if (imp < stop_min_improvment_proc) return true;

    return false;
}