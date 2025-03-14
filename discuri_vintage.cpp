#include "discuri_vintage.h"
#include <stdexcept>

Disc_vintage::Disc_vintage(const string& denumire, float pret_baza, int nr_produse, bool mint, int coeficient)
    : Produs(denumire, pret_baza, nr_produse), mint(mint)
{
    coeficient_valid(coeficient);
    this -> coeficient = coeficient;
}

void Disc_vintage::coeficient_valid(int coeficient)
{
    if (coeficient < 1 || coeficient > 5)
        throw invalid_argument("Coeficientul de raritate trebuie sa fie cuprins intre 1 si 5!");
}

float Disc_vintage::pret() const
{
    float pret = get_pret_baza() + 5;
    pret = pret + 15 * coeficient;
    return pret;
}

void Disc_vintage::afisare() const
{
    cout << "Date despre disc vintage:" << endl;
    Produs::afisare();
    cout << (mint ? "Este mint" : "Nu este mint") << endl;
    cout << "Coeficient de raritate: " << coeficient << endl;
}
