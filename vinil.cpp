#include "Vinil.h"

Vinil::Vinil(const string& denumire, float pret_baza, int nr_produse, const string& casa_discuri, const tm& data_vanzare, const string& trupa, const string& album)
    : Disc(denumire, pret_baza, nr_produse, casa_discuri, data_vanzare, trupa, album)
{

}

float Vinil::pret() const
{
    return Disc::pret();
}

void Vinil::afisare() const
{
    cout << "date despre vinil:" << endl;
    Disc::afisare();
}
