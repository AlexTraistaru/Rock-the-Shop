#ifndef DISCURI_H_INCLUDED
#define DISCURI_H_INCLUDED

#include "Produs.h"
#include <ctime>
#include <iomanip>

class Disc : public Produs
{
    string casa_discuri;
    tm data_vanzare;
    string trupa;
    string album;

public:
    Disc(const string& denumire = "", float pret_baza = 0.0, int nr_produse = 0, const string& casa_discuri ="", const tm& data_vanzare ={}, const string& trupa = "", const string& album = "");

    float pret() const override;

    void afisare() const override;
};

#endif // DISCURI_H_INCLUDED
