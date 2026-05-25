#include <iostream>
#include <math.h> // Potrzebne do funkcji fabs()
#include "TAlgorithm.h"

using namespace std;

// Konstruktor - ustawia limity i dynamicznie tworzy pierwszą populację [cite: 1291]
TAlgorithm::TAlgorithm(unsigned int candidates_count, unsigned int max_population_count, unsigned int min_improvment_proc)
{
    stop_max_population_count = max_population_count;
    stop_min_improvment_proc = min_improvment_proc;
    wsk_population_pres = new TPopulation{ candidates_count };
}

// Destruktor - zwalnia pamięć [cite: 1291]
TAlgorithm::~TAlgorithm()
{
    delete wsk_population_pres;
    delete wsk_population_prev;
    cout << "Usunieto obiekt klasy TAlgorithm\n";
}

// Sprawdzenie, czy osiągnęliśmy maksymalną liczbę populacji [cite: 1418-1424]
bool TAlgorithm::is_max_population()
{
    unsigned int _id_pres = wsk_population_pres->get_id();
    return (_id_pres == stop_max_population_count);
}

// Sprawdzenie, czy poprawa jest mniejsza niż wymagane minimum [cite: 1428-1443]
bool TAlgorithm::is_min_improvment()
{
    TPopulation population_pres = (*wsk_population_pres);
    TPopulation population_prev = (*wsk_population_prev);

    double best_val_pres = population_pres.get_best_val();
    double best_val_prev = population_prev.get_best_val();

    // Różnica w procentach (używamy fabs() do wartości bezwzględnej)
    int improvment = fabs(best_val_prev - best_val_pres) / best_val_prev * 100;
    return (improvment <= stop_min_improvment_proc);
}

// Główny sędzia - decyduje czy przerywamy [cite: 1451-1485]
bool TAlgorithm::is_stop()
{
    bool stop = false;

    if (!wsk_population_prev) // Rozpatrywana pierwsza populacja (brak poprzedniej)
    {
        stop = is_max_population();
    }
    else
    {
        bool stop_case1 = is_max_population();
        bool stop_case2 = is_min_improvment();
        stop = stop_case1 || stop_case2;
    }
    return stop;
}

// Główna pętla algorytmu [cite: 1370-1407]
void TAlgorithm::run()
{
    bool stop = false;

    // Pętla działa, dopóki nie ma poprzedniej populacji (start) ALBO nie ma sygnału stop [cite: 1373]
    while (!wsk_population_prev || !stop)
    {
        wsk_population_pres->calculate();

        cout << "== Population #" << wsk_population_pres->get_id();
        cout << " || best val: " << wsk_population_pres->get_best_val() << endl;

        stop = is_stop();

        if (!stop)
        {
            unsigned int candidates_count = wsk_population_pres->get_candidates_count();

            delete wsk_population_prev; // Sprzątamy starą populację [cite: 1412]
            wsk_population_prev = wsk_population_pres; // Obecna staje się stara [cite: 1413]

            // Tymczasowe rozwiązanie: tworzenie kolejnej losowej populacji [cite: 1414]
            wsk_population_pres = new TPopulation{ candidates_count };
        }
    }
}