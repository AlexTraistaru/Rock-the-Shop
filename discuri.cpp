#include "discuri.h"

Disc::Disc(const string& denumire, float pret_baza, int nr_produse, const string& casa_discuri, const tm& data_vanzare, const string& trupa, const string& album)
    : Produs(denumire, pret_baza, nr_produse), casa_discuri(casa_discuri), data_vanzare(data_vanzare), trupa(trupa), album(album)
{

}

float Disc::pret() const
{
    return get_pret_baza() + 5;
}

void Disc::afisare() const
{
    Produs::afisare();
    cout << "Casa discuri: " << casa_discuri << endl;
    cout << "Data vanzare: " << put_time(&data_vanzare, "%d.%m.%Y") << endl;
    cout << "Trupa: " << trupa << endl;
    cout << "Album: " << album << endl;
}
