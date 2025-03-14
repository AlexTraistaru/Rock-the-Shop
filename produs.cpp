#include "Produs.h"

int Produs::cnt = 1001;

Produs::Produs(const string& denumire, float pret_baza, int nr_produse)
    : id(cnt++), denumire(denumire), pret_baza(pret_baza), nr_produse(nr_produse)
{

}

Produs::~Produs()
{

}

void Produs::afisare() const
{
    cout << "Id: " << id << endl;
    cout <<" Denumire: " << denumire << endl;
    cout << "Pret de baza: " << pret_baza << endl;
    cout << "Numarul de produse: " << nr_produse << endl;
}

void Produs::scade_nr_produse(int scos)
 {
        if (scos <= 0)
            throw invalid_argument("Numarul de produse pe care trebuie sa il scadeti trebuie sa ie mai mare ca 0");
        if (scos > nr_produse)
            throw runtime_error("Pe stoc sunt mai putine produse decat doriti sa stergeti pentru: " + denumire);
        nr_produse -= scos;
}
