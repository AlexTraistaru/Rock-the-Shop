#include "comenzi.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <algorithm>

using namespace std;

Comanda::Comanda(int id, const tm& data_primire, int durata_executie, float valoare, const vector<string>& discuri, const vector<string>& vestimentare)
    : id(id), data_primire(data_primire), durata_executie(durata_executie), valoare(valoare), discuri(discuri), vestimentare(vestimentare)
{

}

void Comanda::afisare() const
{
    cout << "afisare date despre comada " << id << " :" << endl;
    cout << "Data primire: " << put_time(&data_primire, "%d.%m.%Y") << endl;
    cout << "Durata procesarii: " << durata_executie << " secunde" << endl;
    cout << "Valoarea comenzii: " << valoare << " RON" << endl;
    cout << "Produse:" << endl;
    cout << "Discuri: ";
    for (auto i = discuri.begin(); i != discuri.end(); i++)
        cout << *i << " ";

    cout << "Vestimentare: ";
    for (auto i = vestimentare.begin(); i != vestimentare.end(); i++)
        cout << *i << " ";
    cout << "\n";
}

void Comanda::validare_comanda(const vector<Produs*>& produse_stoc)
{
    if (valoare < 100.0)
        throw invalid_argument("Comanda invalida: valoarea totala este sub 100 RON");
    if (discuri.size() > 5)
        throw invalid_argument("Comanda invalida: depaseste 5 discuri");
    if (vestimentare.size() > 3)
        throw invalid_argument("Comanda invalida: depaseste 3 articole vestimentare");

    ///aici verific stocul pentru discuri
    for (const auto& disc : discuri)
    {
        auto i = find_if(produse_stoc.begin(), produse_stoc.end(),
            [&disc](Produs* produs)
                         {
                return produs->get_denumire() == disc && produs->get_nr_produse() > 0;
            });

        if (i == produse_stoc.end()) {
            throw invalid_argument("Produsul " + disc + " nu se afla pe stoc");
        }
    }

    ///aici verific stocul pentru articole vestimentare
    for (const auto& vestim : vestimentare)
    {
        auto i = find_if(produse_stoc.begin(), produse_stoc.end(),
            [&vestim](Produs* produs) {
                return produs->get_denumire() == vestim && produs->get_nr_produse() > 0;
            });

        if (i == produse_stoc.end()) {
            throw invalid_argument("Produsul " + vestim + " nu se afla pe stoc");
        }
    }
}

void Comanda::scadere_timp_executie()
{
    this -> durata_executie--;
}

