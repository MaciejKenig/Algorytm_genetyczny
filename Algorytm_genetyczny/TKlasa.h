#pragma once

class TKlasa
{
private:
    static unsigned int count; 

public:
    static unsigned int vector_size; 
    int init_val;
    unsigned int id;

    TKlasa(int init_val);
    void set_vector_size(unsigned int size);
    void set_init_val(int init_val);
    void info();
};
