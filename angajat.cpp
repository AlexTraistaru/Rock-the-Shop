#include "angajat.h"

int Angajat::contor = 101; ///id ul primului angajat este 101, dupa care se incrementeaza la 102, 103, 104 ...

Angajat::Angajat(string nume, string prenume, const string& CNP, const tm& data_angajare) :
id(contor++), data_angajare(data_angajare)
{
    nume_prenume_valid(nume);
    this -> nume = nume;
    nume_prenume_valid(prenume);
    this -> prenume = prenume;
    CNP_valid(CNP);
    this -> CNP = CNP;
}

Angajat::~Angajat()
{

}

void Angajat::citire()
{
    ///id ul se genereaza automat

    try
    {
        cout << "nume: "; cin >> nume;
        nume_prenume_valid(nume);
    } catch (const exception& e) {
        cout << "eroarea: " << e.what() << endl;
        }

    try
    {
        cout << "prenume: "; cin >> prenume;
        nume_prenume_valid(prenume);
    } catch (const exception& e) {
        cout << "eroarea: " << e.what() << endl;
        }

    try
    {
        cout << "CNP: "; cin >> CNP;
        CNP_valid(CNP);
    } catch (const exception& e){
        cout << "eroarea: " << e.what() << endl;
        }


     try
    {
        string data_ang;
        cout << "data de angajare: (NU UITATI CA DATA SE SCRIE IN FORMATUL DD.MM.YYYY!)"; cin >> data_ang;
        tm data_angajare = data_din_string_in_tm(data_ang);
    } catch (const exception& e){
        cout << "eroarea: " << e.what() << endl;
        }
}

void Angajat::afisare() const
{
    cout << "id: " << id << endl;
    cout << "nume: " << nume << endl;
    cout << "prenume: " << prenume << endl;
    cout << "CNP: " << CNP << endl;
    cout << "data de angajare: " << put_time(&data_angajare, "%d.%m.%Y") << endl;
}

void Angajat::CNP_valid(const string& cnp)
{
    if (cnp.size() != 13)
        throw invalid_argument("CNP ul trebuie sa aiba 13 cifre!");

    for (int i = 0; i < cnp.size(); i++)
        if (cnp[i] < '0' || cnp[i] > '9')
            throw invalid_argument("CNP ul trebuie sa aiba doar cifre!");
}

void Angajat::nume_prenume_valid(const string& a)
{
    if (a.size() < 3 || a.size() > 30)
        throw invalid_argument("textul introdus trebuie sa aiba intre 3 si 30 de caractere!");
}

void Angajat::modificare_nume(const string& nume_nou)
{
    nume_prenume_valid(nume_nou);
    nume = nume_nou;
}

tm Angajat::data_din_string_in_tm(const string& data)
{
    if (data.size() != 10 || data[2] != '.' || data[5] != '.')
        throw invalid_argument("Data trebuie sa aiba formatul DD.MM.YYYY!"); ///aici am verificat ca data sa fie in formatul specificat, respectiv sa aiba "." intre zi, luna si an

    int zi = stoi(data.substr(0, 2)); ///am extras ziua din data
    int luna = stoi(data.substr(3, 2)); ///luna
    int an = stoi(data.substr(6, 4)); ///anul

    if (luna < 1 || luna > 12)
        throw invalid_argument("Luna este invalida!");
    if (zi < 1 || zi > 31)
        throw invalid_argument("Ziua este invalida!");
    if (an > 2025)
        throw invalid_argument("Anul este invalid!");

    ///acum construiesc structura tm
    tm data_ = {};
    data_.tm_mday = zi;
    data_.tm_mon = luna - 1; ///luna este intre 0 si 11
    data_.tm_year = an - 1900; ///scad 1900 pentru a respecta conventia tm_year, de exemplu pentru anul 2025, tm_year este 125
    return data_;
}
