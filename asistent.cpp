#include "asistent.h"

Asistent::Asistent(string nume, string prenume, const string& CNP, const tm& data_angajare) :
    Angajat(nume, prenume, CNP, data_angajare)
{

}

void Asistent::afisare() const
{
    cout << "afisare date asistent: " << endl;
    Angajat::afisare();
}

void Asistent::citire()
{
    cout << "cititi date despre asistent:" << endl;
    Angajat::citire();
}

float Asistent::salariu(int anul_curent) const
{
    int anul_angajare = get_data_angajare().tm_year + 1900;
    int vechime = anul_curent - anul_angajare;
    float salariu_baza = 3500.0;
    float salariu_final = salariu_baza + vechime * 100.0;
    return salariu_final * 0.75;
}
