#ifndef COMENZI_H_INCLUDED
#define COMENZI_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <ctime>
#include "produs.h"

using namespace std;

class Comanda
{
private:
    int id;
    tm data_primire;
    int durata_executie; ///secunde
    float valoare;
    vector<string> discuri;
    vector<string> vestimentare;

public:
    Comanda(int id = 0, const tm& data_primire = {}, int durata_executie = 0, float valoare = 0.0, const vector<string>& discuri = {}, const vector<string>& vestimentare = {});

    int getId() const
    {
        return id;
    }

    const tm& get_data_primire() const
    {
        return data_primire;
    }

    int get_durata_executie() const
    {
        return durata_executie;
    }

    float get_valoare() const
    {
        return valoare;
    }

    const vector<string>& get_discuri() const
    {
        return discuri;
    }

    const vector<string>& get_vestimentare() const
    {
        return vestimentare;
    }

    void afisare() const;

    void validare_comanda(const vector<Produs*>& produse_stoc);

    void scadere_timp_executie();


};

#endif // COMENZI_H_INCLUDED
