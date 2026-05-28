#include <iostream>
#include <cstdlib> 
#include <time.h>

#include "TParam.h"
#include "TCandidate.h"
#include "TPopulation.h"

using namespace std;

int main()
{
    srand((unsigned int)time(0));

    TParam gen{ "gen1", 0, 10, 0.1 };
    gen.info();
    TParam gen_copy(gen);
    gen_copy.info();
    std::cout << "\n\n";

    TCandidate os1{};
    os1.rate();
    os1.info();
    TCandidate os_copy{ os1 };
    os_copy.info();
    std::cout << "\n\n";

 
    TPopulation pop1{ 5 };
    pop1.calculate();
    pop1.info();
    TPopulation pop_copy{ pop1 };
    pop_copy.info();

    std::cout << "\n\n\n";
    return 0;
}