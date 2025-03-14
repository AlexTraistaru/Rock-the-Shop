#ifndef PRODUS_H_INCLUDED
#define PRODUS_H_INCLUDED

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Produs
{
    const int id;
    static int cnt;
    string denumire;
    float pret_baza;
    int nr_produse;

public:
    Produs(const string& denumire = "", float pret_baza = 0.0, int nr_produse = 0);

    virtual float pret() const = 0; /// func virtuala pura

    virtual void afisare() const;

    virtual ~Produs();

    int get_id() const
    {
        return id;
    }

    float get_pret_baza() const
    {
        return pret_baza;
    }

    string get_denumire() const
    {
        return denumire;
    }

    int get_nr_produse() const
    {
        return nr_produse;
    }

    void set_nr_produse(int n)
    {
        nr_produse = n;
    }

    void scade_nr_produse(int scos);
};

#endif // PRODUS_H_INCLUDED
