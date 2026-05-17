#include <iostream>
#include <cstdlib> 
#include <time.h>   
#include "TCandidate.h" 

using namespace std;

int main()
{
    srand(time(0)); // Uruchomienie generatora liczb losowych

    TCandidate os1{}; // Tworzymy nowego osobnika (w tle automatycznie losują się geny)

    os1.rate(); // Każemy osobnikowi obliczyć swoją ocenę na podstawie wylosowanych genów
    os1.info(); // Wypisujemy wyniki w konsoli

    return 0;
}