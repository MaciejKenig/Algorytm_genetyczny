#include <iostream>
#include <cstdlib> // srand
#include <time.h>
#include <vector>
#include "TCandidate.h"
#include "TCandidate_Zad1.h"
#include "TCandidate_Zad2.h"

using namespace std;

int main()
{
    srand((unsigned int)time(0));

    int typ_osobnika;
    int liczba_osobnikow;

    cout << "Ktory osobnik [0-2]: ";
    cin >> typ_osobnika;

    cout << "Ilu osobnikow utworzyc? ";
    cin >> liczba_osobnikow;

    vector<TCandidate*> candidates;

    for (int i = 0; i < liczba_osobnikow; i++)
    {
        if (typ_osobnika == 0)
        {
            candidates.push_back(new TCandidate{}); 
        }
        else if (typ_osobnika == 1)
        {
            candidates.push_back(new TCandidate_Zad1{}); 
        }
        else if (typ_osobnika == 2)
        {
            candidates.push_back(new TCandidate_Zad2{}); 
        }
        else
        {
            cout << "Niepoprawny typ!" << endl;
            return 1;
        }
    }

 
    for (size_t i = 0; i < candidates.size(); i++)
    {
        candidates[i]->rate();
        candidates[i]->info(); 
    }

 
    for (size_t i = 0; i < candidates.size(); i++)
    {
        delete candidates[i];
    }

    std::cout << "\n\n\n";
    return 0;
}