#include <iostream>
#include <cstdlib>
#include <time.h>
#include "TCandidate_Zad3.h"
#include "TPopulation.h"

using namespace std;

int main()
{
    srand((unsigned int)time(0));

   
    TCandidate* pattern = new TCandidate_Zad3{};
    TPopulation pop{ 10, pattern };

  
    pop.calculate(); 

  
    pop.info();

    cout << "Wylosowani osobnicy: ";


    for (int i = 0; i < 10; i++) 
    {
        TCandidate* chosen = pop.promote_candidate();

        for (unsigned int idx = 0; idx < pop.get_candidates_count(); idx++)
        {
            if (chosen == pop.get_candidate_wsk(idx))
            {
                cout << "#" << idx << ", "; // 
                break;
            }
        }
    }

    cout << endl;
    delete pattern;

    std::cout << "\n\n\n";
    return 0;
}