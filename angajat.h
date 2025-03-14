#ifndef ANGAJAT_H_INCLUDED
#define ANGAJAT_H_INCLUDED

#include <iostream>
#include <string.h>
#include <stdexcept>
#include <ctime>
#include <iomanip> ///pentru functia put_time

using namespace std;

class Angajat
{
   const int id; ///const ca sa nu mai fie modificat
   static int contor; ///generez id uri unice
   string nume;
   string prenume;
   string CNP;
   tm data_angajare; ///in format DD.MM.YYYY

public:
    Angajat(string nume = "", string prenume = "", const string& CNP = "", const tm& data_angajare = {});

    virtual ~Angajat();

    virtual void citire();

    virtual void afisare() const;

    virtual float salariu(int anul_curent) const = 0;
    ///functie virtuala pura, fortez fiecare clasa derivata sa aiba propria implementare a acestei functii

    int get_id() const
    {
        return id;
    }

    string get_nume() const
    {
        return nume;
    }

    string get_prenume() const
    {
        return prenume;
    }

    string get_CNP() const
    {
        return CNP;
    }

    static void CNP_valid(const string& cnp);

    static void data_angajare_valida(const string& data_ang);

    static void nume_prenume_valid(const string& a);

    void modificare_nume(const string& nume_nou);

    static tm data_din_string_in_tm(const string& data);

    tm get_data_angajare() const
    {
        return data_angajare;
    }
};

#endif // ANGAJAT_H_INCLUDED
