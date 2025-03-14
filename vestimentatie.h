#ifndef VESTIMENTATIE_H_INCLUDED
#define VESTIMENTATIE_H_INCLUDED

#include "Produs.h"

class Vestimentatie : public Produs
{
    string culoare;
    string marca;

public:
    Vestimentatie(const string& denumire = "", float pret_baza = 0.0, int nr_produse = 0, const string& culoare = "", const string& marca = "");

    float pret() const override;

    void afisare() const override;
};

#endif // VESTIMENTATIE_H_INCLUDED
