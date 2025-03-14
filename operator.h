
#ifndef OPERATOR_H_INCLUDED
#define OPERATOR_H_INCLUDED

#include "angajat.h"
#include "comenzi.h"
#include <vector>

class Operator : public Angajat
{
    float valoare_comenzi;
    int comenzi_curente;
    int comenzi_total=0;
    vector<Comanda> comenzi;

public:
    Operator(string nume = "", string prenume = "", const string& CNP = "", const tm& data_angajare = {}, int comenzi_curente = 0, float valoare_comenzi = 0.0);

    void afisare() const override;

    void citire() override;

    float salariu(int anul_curent) const;

    int get_nr_comenzi() const
    {
        return comenzi_curente;
    }

    float get_val_totala_comenzi() const
    {
        return valoare_comenzi;
    }

    void adaugare_comanda(const Comanda& comanda);

    bool poate_realiza_comanda() const;

    void finalizare_comanda();

    void procesare_comanda();

    int get_comenzi_totale(){ return comenzi_total;}
};

#endif // OPERATOR_H_INCLUDED
