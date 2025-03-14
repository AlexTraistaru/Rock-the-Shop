#ifndef VINIL_H_INCLUDED
#define VINIL_H_INCLUDED

#include "discuri.h"

class Vinil : public Disc
{
public:
    Vinil(const string& denumire = "", float pret_baza = 0.0, int nr_produse = 0, const string& casa_discuri = "", const tm& data_vanzare = {}, const string& trupa = "", const string& album = "");

    float pret() const override;

    void afisare() const;
};

#endif // VINIL_H_INCLUDED
