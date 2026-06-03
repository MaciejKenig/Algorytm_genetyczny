#include <iostream>
#include <math.h>
#include "TCandidate.h"

using namespace std;


TCandidate::TCandidate()
{
    //init_vector();                 
    gens_count = (int)genotype.size(); 
    mark = 0;                      
    rand_gens_val();              
}


TCandidate::TCandidate(const TCandidate& original)
{
    mark = original.get_mark();  

    for (int i = 0; i < original.gens_count; i++) 
    {
        double x_start = original.genotype[i].get_x_start(); 
        double x_end = original.genotype[i].get_x_end();     
        double dx = original.genotype[i].get_dx();          


        TParam p(x_start, x_end, dx);
        genotype.push_back(p);

        
        double val = original.get_gen_val(i); 
        genotype[i].set_val(val);            
    }
    gens_count = (int)genotype.size();
}

//void TCandidate::rate()
//{
//    double x1 = genotype[0].get_val(); 
//    double x2 = genotype[1].get_val(); 
//    mark = pow(x1, 2) + x2;            
//}

//void TCandidate::init_vector()
//{
//    genotype.push_back(TParam("x1", 0, 100, 1)); 
//    genotype.push_back(TParam("x2", 0, 100, 1)); 
//}

void TCandidate::rand_gens_val()
{
    for (int i = 0; i < gens_count; i++)
    {
        genotype[i].set_rand_val();
    }
}

void TCandidate::info()
{
    cout << "\n\n";
    cout << "========================\n";
    cout << "==\n";
    cout << "== gens count: " << gens_count << "\n";

    for (int i = 0; i < gens_count; i++)
    {
        cout << "== \"" << genotype[i].get_name()
            << "\" value: " << genotype[i].get_val()
            << "\n";
    }
    cout << "==\n";
    cout << "== rate: " << mark << "\n";
    cout << "========================\n";
}