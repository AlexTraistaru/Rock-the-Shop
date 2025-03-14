#include "operator.h"

Operator::Operator(string nume, string prenume, const string& CNP, const tm& data_angajare, int comenzi_curente, float valoare_comenzi) :
    Angajat(nume, prenume, CNP, data_angajare), comenzi_curente(comenzi_curente), comenzi_total(comenzi_curente), valoare_comenzi(valoare_comenzi)
{

}

void Operator::afisare() const
{
    cout << "Afisare date operator:" << endl;
    Angajat::afisare();
    cout << "acest operator are " << comenzi_curente << " comenzi curente" << endl;
    cout << "valoarea totala a comenzilor: " << valoare_comenzi << endl;
}

void Operator::citire()
{
    cout << "cititi date despre operator: " << endl;
    Angajat::citire();
}

float Operator::salariu(int anul_curent) const
{
    int anul_angajare = get_data_angajare().tm_year + 1900;
    int vechime = anul_curent - anul_angajare;
    float salariu_baza = 3500.0;
    float bonus = valoare_comenzi * 0.005;
    float salariu_final = salariu_baza + vechime * 100.0 + bonus;
    return salariu_final * 1.0;
}

void Operator::adaugare_comanda(const Comanda& comanda)
{
    if (comenzi_curente >= 3)
        throw runtime_error("Operatorul are deja 3 comenzi în desfășurare.");

    comenzi.push_back(comanda); ///aici adaug comanda in vectorul de comenzi curente

    valoare_comenzi += comanda.get_valoare(); ///aici actualizez valoarea totala a comenzii si numarul de comenzi
    comenzi_curente++;
    comenzi_total=comenzi_curente;
}

bool Operator::poate_realiza_comanda() const
{
    return comenzi_curente < 3;
}

void Operator::procesare_comanda()
{
    for(size_t i = 0; i < 3 && i < comenzi.size(); i++)
    {
        Comanda& comanda_curenta = comenzi[i];
        if (comanda_curenta.get_durata_executie() >= 1)
            {
                cout << "Operatorul: " << get_nume() << " executa comanda cu id-ul: " << comanda_curenta.getId() << ", durata de executie ramasa: " << comanda_curenta.get_durata_executie() << endl;
                comanda_curenta.scadere_timp_executie();
            }
        else if (comanda_curenta.get_durata_executie() == 0)
            {
                cout << "Operatorul: " << get_nume() << " a terminat comanda cu id-ul: " << comanda_curenta.getId() << endl;
                comenzi.erase(comenzi.begin() + i); ///sterg comanda din vector
                comenzi_curente--;
                i--;
            }
    }

}
