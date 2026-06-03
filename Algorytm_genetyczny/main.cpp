#include <iostream>
#include <cstdlib>
#include <time.h>
#include "TCandidate_Zad1.h"
#include "TCandidate_Zad2.h"
#include "TCandidate_Zad3.h"
#include "TAlgorithm.h"

using namespace std;

int main()
{
    srand((unsigned int)time(0));

    TCandidate* pattern = nullptr;
    int count = 0; 
    int _type = -1; 

    cout << "Ktory osobnik [1-3]: "; 
    cin >> _type; 

    cout << "Ilu osobnikow w populacji? "; 
    cin >> count; 

    switch (_type) 
    {
    case 1:
        pattern = new TCandidate_Zad1{}; 
        break;
    case 2:
        pattern = new TCandidate_Zad2{}; 
        break;
    case 3:
        pattern = new TCandidate_Zad3{}; 
        break;
    default:
        pattern = new TCandidate_Zad1{}; 
        break;
    }

    unsigned int candidates_count = count;
    unsigned int max_population_count = 20; 
    unsigned int min_improvment_proc = 2; 

  
    TAlgorithm task(pattern, candidates_count, max_population_count, min_improvment_proc); 
    task.run(); 

    
    delete pattern;

    std::cout << "\n\n\n";
    return 0;
}