#ifndef DISCURI_VINTAGE_H_INCLUDED
#define DISCURI_VINTAGE_H_INCLUDED

#include "Produs.h"

class Disc_vintage : public Produs
{
    bool mint;
    int coeficient;

public:
    Disc_vintage(const string& denumire = "", float pret_baza = 0.0, int nr_produse = 0, bool mint = true, int coeficient = 1);

    float pret() const override;

    void afisare() const override;

    static void coeficient_valid(int coeficient); ///verifica ca acel coeficient sa fie intre 1 si 5
};

#endif // DISCURI_VINTAGE_H_INCLUDED
