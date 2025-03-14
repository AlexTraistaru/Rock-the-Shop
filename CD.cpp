#include "CD.h"

CD::CD(const string& denumire, float pret_baza, int nr_produse, const string& casa_discuri, const tm& data_vanzare, const string& trupa, const string& album)
    : Disc(denumire, pret_baza, nr_produse, casa_discuri, data_vanzare, trupa, album)
{

}

float CD::pret() const
{
    return Disc::pret();
}

void CD::afisare() const
{
    cout << "date despre CD:" << endl;
    Disc::afisare();
}
