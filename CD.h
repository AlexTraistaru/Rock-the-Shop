#ifndef CD_H_INCLUDED
#define CD_H_INCLUDED

#include "discuri.h"

class CD : public Disc
{
public:
    CD(const string& denumire = "", float pret_baza = 0.0, int nr_produse = 0, const string& casa_discuri = "", const tm& data_vanzare = {}, const string& trupa = "", const string& album = "");

    float pret() const override;

    void afisare() const override;
};

#endif // CD_H_INCLUDED
