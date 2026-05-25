#include <iostream>
#include <cstdlib> 
#include <time.h>   

#include "TPopulation.h" 

using namespace std;


int main()
{
    srand(time(0));

    TPopulation pop(10);
    
    cout << "Zaraz po utworzenu obiektu klasy TPopulation";
    pop.info();
	cout << "\n\n";

	cout << "Po wykonanych obliczeniach";
    pop.calculate();
	pop.info();
    cout << "\n\n";

    cout << "Najlepszy osobnik:\n";

    pop.get_best_candidate().info();

    return 0;
}