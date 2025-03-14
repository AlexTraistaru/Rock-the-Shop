#ifndef MAGAZIN_H_INCLUDED
#define MAGAZIN_H_INCLUDED

#include <vector>
#include "angajat.h"
#include "manager.h"
#include "operator.h"
#include "asistent.h"
#include "produs.h"
#include "vestimentatie.h"
#include "vinil.h"
#include "discuri_vintage.h"
#include "CD.h"
#include "comenzi.h"
#include <ctime>
#include <iomanip>
#include <queue>
#include <fstream>
#include <stdexcept>

using namespace std;

class Magazin
{
    vector<Angajat*> angajati;

    vector<Produs*> produse;

    vector<Operator*> operatori;

    queue<Comanda> comenzi_primite; ///aceasta este coada de comenzi primite de la "clienti"
public:
    Magazin();

    ~Magazin();

    void meniu();

    void meniu_angajati(Magazin& magazin);

    void meniu_produse(Magazin& magazin);

    ///pentru angajati
    void adaugare_angajat();

    void stergere_angajat(int id);

    void modificare_angajat(int id);

    void afisare_angajat(int id) const;

    void afisare_toti_angajati() const;

    bool verificare_angajati() const; ///aceasta functie verifica ca magazinul sa aiba minim 1 manager, 3 operatori si 1 asistent

    ///pentru produse
    void adaugare_produs();

    void stergere_produs(int id);

    void modificare_produs(int id);

    void afisare_produs(int id) const;

    void afisare_toate_produse() const;

    bool verificare_produse() const; ///aceasta functie verifica ca stocul de produse sa aiba minim 2 produse din fiecare tip de produs

    ///pentru procesare
    void citire_comenzi(const string& fisier);

    void procesare_comenzi();

    void afisare_stare_operatori() const;

    bool sunt_comenzi_in_desfasurare() const;

    void actualizare_stoc(const Comanda& comanda);

    ///raportare
    void angajat_cele_mai_multe_comenzi();

    void top_valoare_comenzi();

    void top_3_salariu();
};


#endif // MAGAZIN_H_INCLUDED
