#include <iostream>
#include "TKlasa.h"

using namespace std;

int main()
{
 
    TKlasa obiekt1{-3};
    TKlasa obiekt2{0};
    TKlasa obiekt3{5};


    obiekt1.info();
    obiekt2.info();
    obiekt3.info();

    cout << "====================\n\n"; 

 
    obiekt1.set_vector_size(3); 
    obiekt3.set_init_val(2);     

    obiekt1.info(); 
    obiekt2.info(); 
    obiekt3.info(); 

    return 0;
}