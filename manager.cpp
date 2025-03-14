#include "manager.h"

Manager::Manager(string nume, string prenume, const string& CNP, const tm& data_angajare) :
Angajat(nume, prenume, CNP, data_angajare)
{

}

void Manager::citire()
{
    cout << "citit datele pentru manager:" << endl;
    Angajat::citire();
}

void Manager::afisare() const
{
    cout << "afisare date despre manager:" << endl;
    Angajat::afisare();
}

float Manager::salariu(int anul_curent) const
{
    int anul_angajare = get_data_angajare().tm_year + 1900; ///anul in tm este an - 1900 asa ca la revenire adunam 1900
    int vechime = anul_curent - anul_angajare;
    float salariu_baza = 3500.0;
    float salariu_final = salariu_baza + vechime * 100.0;
    return salariu_final * 1.25;
}
