#include "Vestimentatie.h"

Vestimentatie::Vestimentatie(const string& denumire, float pret_baza, int nr_produse, const string& culoare, const string& marca) :
    Produs(denumire, pret_baza, nr_produse), culoare(culoare), marca(marca)
{

}

float Vestimentatie::pret() const
{
    return get_pret_baza() + 20;
}

void Vestimentatie::afisare() const
{
    cout << "date despre articol vestimentar:" << endl;
    Produs::afisare();
    cout << "Culoare: " << culoare << endl;
    cout << "Marca: " << marca << endl;
}
