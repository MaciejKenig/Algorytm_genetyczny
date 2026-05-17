#include <iostream>
#include "TCandidate.h"

using namespace std;

// KONSTRUKTOR
// Inicjalizujemy geny x1 i x2 na liście inicjalizacyjnej (po dwukropku),
// podając im nazwę, zakres od 0 do 10 oraz krok 1.
TCandidate::TCandidate() : x1("x1", 0, 10, 1), x2("x2", 0, 10, 1)
{
    rate_val = 0;
    rand_gens_val(); // Od razu losujemy startowe wartości genów
}

// Metoda losująca nowe wartości dla obu genów
void TCandidate::rand_gens_val()
{
    x1.set_rand_val(); // Wywołujemy funkcję losującą z klasy TParam
    x2.set_rand_val();
}

// Funkcja oceny osobnika
// Zgodnie ze wzorem : x1^2 + x2 
void TCandidate::rate()
{
    double v1 = x1.get_val(); // Pobieramy rzeczywistą wartość liczbową genu x1 
    double v2 = x2.get_val(); // Pobieramy rzeczywistą wartość liczbową genu x2 

    rate_val = (v1 * v1) + v2; // Obliczamy wzór i zapisujemy do oceny osobnika
}

// Funkcja wyświetlająca końcowy raport w konsoli

void TCandidate::info()
{
    cout << "========================\n";
    cout << "==\n";
    cout << "== gens count: 2\n";
    cout << "== \"" << x1.get_name() << "\" value: " << x1.get_val() << "\n";
    cout << "== \"" << x2.get_name() << "\" value: " << x2.get_val() << "\n";
    cout << "==\n";
    cout << "== rate: " << rate_val << "\n";
    cout << "========================\n";
}