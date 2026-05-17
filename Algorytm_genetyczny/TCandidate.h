#pragma once
#include "TParam.h"

class TCandidate
{
private:
    // GENOTYP OSOBNIKA
    // Tworzymy dwa geny, które są po prostu obiektami naszej klasy TParam
    TParam x1;
    TParam x2;

    // OCENA
    // Zmienna, w której zapiszemy wynik obliczeń z funkcji rate()
    double rate_val;

public:
    // KONSTRUKTOR
    // Wywoływany, gdy w main.cpp piszesz: TCandidate os1{};
    TCandidate();

    // METODY KLASY
    void rand_gens_val(); // Losuje wartości początkowe dla x1 i x2
    void rate();          // Podstawia geny do wzoru x1^2 + x2 i zapisuje wynik w rate_val
    void info();          // Wyświetla w konsoli stan osobnika (wartości genów i ocenę)
};
