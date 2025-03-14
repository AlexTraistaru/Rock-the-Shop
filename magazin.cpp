#include "magazin.h"
#include <iostream>
#include <typeinfo>
#include <algorithm>

using namespace std;

Magazin::Magazin()
{
    try {
        ///am adaugat angajati
        tm data_angajare = Angajat::data_din_string_in_tm("01.01.2010");
        angajati.push_back(new Manager("Popescu", "Mihai", "5030406430020", data_angajare));

        data_angajare = Angajat::data_din_string_in_tm("02.02.2011");
        angajati.push_back(new Operator("Ionescu", "Ion", "1234567892569", data_angajare));
        operatori.push_back(new Operator("Ionescu", "Ion", "1234567892569", data_angajare));

        data_angajare = Angajat::data_din_string_in_tm("03.03.2012");
        angajati.push_back(new Operator("Andronie", "Ionut", "1234567894123", data_angajare));
        operatori.push_back(new Operator("Andronie", "Ionut", "1234567894123", data_angajare));

        data_angajare = Angajat::data_din_string_in_tm("04.04.2013");
        angajati.push_back(new Operator("Briceag", "Valentin", "1234567895879", data_angajare));
        operatori.push_back(new Operator("Briceag", "Valentin", "1234567895879", data_angajare));

        data_angajare = Angajat::data_din_string_in_tm("05.05.2014");
        angajati.push_back(new Asistent("Popiloiu", "Ionela", "1234567891256", data_angajare));

        ///am adaugat produse
        ///Vestimentatie(const string& denumire = "", float pret_baza = 0.0, int nr_produse = 0, const string& culoare = "", const string& marca = "");
        produse.push_back(new Vestimentatie("Tricou1", 100.0, 5, "Alb", "Marca1"));
        produse.push_back(new Vestimentatie("Tricou2", 50.0, 5, "Alb", "Marca2"));
        produse.push_back(new Vestimentatie("Tricou3", 50.0, 5, "Alb", "Marca2"));
        produse.push_back(new Vestimentatie("Tricou4", 50.0, 5, "Alb", "Marca2"));
        produse.push_back(new Vestimentatie("Tricou5", 50.0, 5, "Alb", "Marca2"));

        ///Vinil(const string& denumire = "", float pret_baza = 0.0, int nr_produse = 0, const string& casa_discuri = "", const tm& data_vanzare = {}, const string& trupa = "", const string& album = "");
        tm data_vanzare = Angajat::data_din_string_in_tm("01.01.1991");
        produse.push_back(new Vinil("Vinil1", 100.0, 5, "Casa", data_vanzare, "Trupa", "Album"));
        data_vanzare = Angajat::data_din_string_in_tm("01.01.1987");
        produse.push_back(new Vinil("Vinil2", 100.0, 5, "Casa", data_vanzare, "Trupa", "Album"));
        data_vanzare = Angajat::data_din_string_in_tm("01.01.1988");
        produse.push_back(new Vinil("Vinil3", 100.0, 5, "Casa", data_vanzare, "Trupa", "Album"));
        data_vanzare = Angajat::data_din_string_in_tm("01.01.1989");
        produse.push_back(new Vinil("Vinil4", 100.0, 5, "Casa", data_vanzare, "Trupa", "Album"));
        data_vanzare = Angajat::data_din_string_in_tm("01.01.1985");
        produse.push_back(new Vinil("Vinil5", 100.0, 5, "Casa", data_vanzare, "Trupa", "Album"));

        ///CD(const string& denumire = "", float pret_baza = 0.0, int nr_produse = 0, const string& casa_discuri = "", const tm& data_vanzare = {}, const string& trupa = "", const string& album = "");
        data_vanzare = Angajat::data_din_string_in_tm("01.01.2000");
        produse.push_back(new CD("CD1", 50.0, 5, "Casa", data_vanzare, "Trupa", "Album"));
        data_vanzare = Angajat::data_din_string_in_tm("01.01.2000");
        produse.push_back(new CD("CD2", 50.0, 5, "Casa", data_vanzare, "Trupa", "Album"));
        data_vanzare = Angajat::data_din_string_in_tm("01.01.2000");
        produse.push_back(new CD("CD3", 50.0, 5, "Casa", data_vanzare, "Trupa", "Album"));

        ///Disc_vintage(const string& denumire = "", float pret_baza = 0.0, int nr_produse = 0, bool mint = true, int coeficient = 1);
        produse.push_back(new Disc_vintage("Disc_vintage1", 100.0, 3, true, 1));
        produse.push_back(new Disc_vintage("Disc_vintage2", 100.0, 3, false, 2));
        produse.push_back(new Disc_vintage("Disc_vintage3", 100.0, 3, true, 3));
        produse.push_back(new Disc_vintage("Disc_vintage4", 100.0, 3, false, 4));
        produse.push_back(new Disc_vintage("Disc_vintage5", 100.0, 3, true, 5));
    } catch (const exception& e) {
        cout << "Eroare la initializarea magazinului: " << e.what() << endl;
    }
}

Magazin::~Magazin()
{
    for (auto i = angajati.begin(); i != angajati.end(); i++)
        delete *i;
    for (auto i = produse.begin(); i != produse.end(); i++)
        delete *i;
}

bool Magazin::verificare_angajati() const
{
    int cnt_manager = 0, cnt_operator = 0, cnt_asistent = 0;
    string s1 = "Manager", s2 = "Operator", s3 = "Asistent";

    for (auto i = angajati.begin(); i != angajati.end(); i++)
    {
        string tip_angajat = typeid(**i).name(); ///numele clasei obiectului
        if (tip_angajat.find(s1) < tip_angajat.size())
            cnt_manager++;
        else if (tip_angajat.find(s2) < tip_angajat.size())
            cnt_operator++;
        else if (tip_angajat.find(s3) < tip_angajat.size())
            cnt_asistent++;
    }

    if (cnt_manager < 1 || cnt_operator < 3 || cnt_asistent < 1)
    {
        cout << "Magazinul nu poate functiona intrucat nu are minim 1 manager, 3 operatori si 1 asistent!" << endl;
        return false;
    }
    return true;
}

bool Magazin::verificare_produse() const
{
    int cnt_vestimentatie = 0, cnt_CD = 0, cnt_vinil = 0, cnt_disc_vintage = 0;
    string s1 = "Vestimentatie", s2 = "CD", s3 = "Vinil", s4 = "Disc_vintage";

    for (auto i = produse.begin(); i != produse.end(); i++)
    {
        string tip_produs = typeid(**i).name();
        if (tip_produs.find(s1) < tip_produs.size())
            cnt_vestimentatie++;
        else if (tip_produs.find(s2) < tip_produs.size())
            cnt_CD++;
        else if (tip_produs.find(s3) < tip_produs.size())
            cnt_vinil++;
        else if (tip_produs.find(s4) < tip_produs.size())
            cnt_disc_vintage++;
    }

    if (cnt_vestimentatie < 2 || cnt_CD < 2 || cnt_vinil < 2 || cnt_disc_vintage < 2)
    {
        cout << "Magazinul nu poate functiona intrucat nu are minim 2 produse din fiecare tip!" << endl;
        return false;
    }
    return true;
}

///gestiunea angajatilor
void Magazin::adaugare_angajat()
{
    int tip;
    string nume, prenume, cnp, data_angajare;
    cout << "Introduceti tipul angajatului (1 - Manager, 2 - Operator, 3 - Asistent): ";
    cin >> tip;
    cout << "Numele: ";
    cin >> nume;
    cout << "Prenumele: ";
    cin >> prenume;
    cout << "CNP: ";
    cin >> cnp;
    cout << "Introduceti data angajarii in formatul DD.MM.YYYY: ";
    cin >> data_angajare;

    try {
        Angajat::nume_prenume_valid(nume);
        Angajat::nume_prenume_valid(prenume);
        Angajat::CNP_valid(cnp);
        tm data_angajare_tm = Angajat::data_din_string_in_tm(data_angajare);

        int an = stoi(cnp.substr(1, 2));  ///anul nasterii
        int luna = stoi(cnp.substr(3, 2)); ///luna nasterii
        int zi = stoi(cnp.substr(5, 2));  ///ziua nasterii
        int secol;
        if (cnp[0] == '1' || cnp[0] == '2')
            secol = 1900;
        else if (cnp[0] == '5' || cnp[0] == '6')
            secol = 2000;
        an += secol; ///aflu anul complet

        int varsta = data_angajare_tm.tm_year + 1900 - an;
        if (data_angajare_tm.tm_mon < luna - 1 || (data_angajare_tm.tm_mon == luna - 1 && data_angajare_tm.tm_mday < zi))
            varsta--; ///in cazul in care luna si ziua sunt inainte de cele ale nasterii, de exemplu cineva nascut in 2007 poate sa aiba 18 ani in 2025, dar daca nu a ajuns la ziua lui de nastere din 2025

        if (varsta < 18)
            throw invalid_argument("Persoana angajata trebuie sa aiba minim 18 ani la data angajarii!");

        if (tip == 1)
            angajati.push_back(new Manager(nume, prenume, cnp, data_angajare_tm));
        else if (tip == 2)
        {
            angajati.push_back(new Operator(nume, prenume, cnp, data_angajare_tm));
            operatori.push_back(new Operator(nume, prenume, cnp, data_angajare_tm));
        }
        else if (tip == 3)
            angajati.push_back(new Asistent(nume, prenume, cnp, data_angajare_tm));
        else
            cout << "Tip invalid!" << endl;
    } catch (const invalid_argument& e) {
        cout << "Eroare: " << e.what() << endl;
    }
}


void Magazin::modificare_angajat(int id)
{
    for (auto i = angajati.begin(); i != angajati.end(); i++) {
        if ((*i) -> get_id() == id)
        {
            string nume;
            cout << "Introduceti noul nume: ";
            try
            {
                cin >> nume;
                Angajat::nume_prenume_valid(nume);
                (*i) -> modificare_nume(nume);
                cout << "Angajat modificat cu succes" << endl;
            } catch (const invalid_argument& e) {
                cout << "Eroare: " << e.what() << endl;
            }
            return;
        }
    }
    cout << "Angajatul cu ID-ul specificat nu exista" << endl;
}


void Magazin::afisare_angajat(int id) const
{
    for (auto i = angajati.begin(); i != angajati.end(); i++)
        if ((*i) -> get_id() == id)
        {
            (*i) -> afisare();
            return;
        }
    cout << "Angajatul cu ID-ul " << id << " nu exista" << endl;
}

void Magazin::afisare_toti_angajati() const
{
    for (auto i = angajati.begin(); i != angajati.end(); i++)
    {
        (*i) -> afisare();
        cout << endl;
    }
}

void Magazin::stergere_angajat(int id)
{
    for (auto i = angajati.begin(); i != angajati.end(); i++)
        if ((*i) -> get_id() == id)
        {
            delete *i;
            angajati.erase(i); /// sterg pointerul din vector
            cout << "Angajatul cu ID-ul " << id << " a fost sters" << endl;
            return;
        }
    cout << "Angajatul cu ID ul " << id << " nu exista" << endl;
}

///gestiunea produselor
void Magazin::adaugare_produs()
{
    int tip;
    string denumire;
    float pret;
    int nr_produse;
    cout << "Introduceti tipul produsului (1 - Vestimentatie, 2 - Vinil, 3 - CD, 4 - Disc Vintage): ";
    cin >> tip;
    cout << "Introduceti denumirea produsului: ";
    cin >> denumire;
    cout << "Introduceti prețul produsului: ";
    cin >> pret;
    cout << "Introduceti numarul de produse: ";
    cin >> nr_produse;
    try
    {
        if (tip == 1)
        {
            string culoare, marca;
            cout << "Introduceti culoarea: ";
            cin >> culoare;
            cout << "Introduceti marca: ";
            cin >> marca;
            produse.push_back(new Vestimentatie(denumire, pret, nr_produse, culoare, marca));
        }
        else if (tip == 2)
        {
            string casa_discuri, data, trupa, album;
            cout << "Introduceti casa de discuri: ";
            cin >> casa_discuri;
            cout << "Introduceti data in formatul DD.MM.YYYY: ";
            cin >> data;
            tm data_vanzare = Angajat::data_din_string_in_tm(data);
            cout << "Introduceti trupa: ";
            cin >> trupa;
            cout << "Introduceti albumul: ";
            cin >> album;
            produse.push_back(new Vinil(denumire, pret, nr_produse, casa_discuri, data_vanzare, trupa, album));
        }
        else if (tip == 3)
        {
            string casa_discuri, data, trupa, album;
            cout << "Introduceti casa de discuri: ";
            cin >> casa_discuri;
            cout << "Introduceti data in formatul DD.MM.YYYY: ";
            cin >> data;
            tm data_vanzare = Angajat::data_din_string_in_tm(data);
            cout << "Introduceti trupa: ";
            cin >> trupa;
            cout << "Introduceti albumul: ";
            cin >> album;
            produse.push_back(new CD(denumire, pret, nr_produse, casa_discuri, data_vanzare, trupa, album));
        }
        else if (tip == 4)
        {
            bool mint;
            int coeficient;
            cout << "Produsul este mint (1 - Da, 0 - Nu): ";
            cin >> mint;
            cout << "Introduceti coeficientul de raritate (1 - 5): ";
            cin >> coeficient;
            Disc_vintage::coeficient_valid(coeficient);
            produse.push_back(new Disc_vintage(denumire, pret, nr_produse, mint, coeficient));
        }
        else
            cout << "Tip invalid!" << endl;
    } catch (const invalid_argument& e) {
        cout << "Eroare: " << e.what() << endl;
    }
}

void Magazin::stergere_produs(int id)
{
    for (auto i = produse.begin(); i != produse.end(); i++)
        if ((*i) -> get_id() == id)
        {
            delete *i;
            produse.erase(i);
            cout << "Produsul cu ID ul " << id << " a fost sters" << endl;
            return;
        }
    cout << "Produsul cu ID ul " << id << " nu exista" << endl;
}

void Magazin::modificare_produs(int id)
{
    for (auto i = produse.begin(); i != produse.end(); i++)
        if ((*i)->get_id() == id)
        {
            int nr_produse;
            cout << "Introduceti noul numar de produse: ";
            cin >> nr_produse;
            (*i) -> set_nr_produse(nr_produse);
            cout << "Produsul a fost modificat" << endl;
            return;
        }
    cout << "Produsul cu ID-ul " << id << " nu exista" << endl;
}

void Magazin::afisare_produs(int id) const
{
    for (const auto& produs : produse)
        if (produs -> get_id() == id)
        {
            produs -> afisare();
            return;
        }
    cout << "Produsul cu ID-ul " << id << " nu exista" << endl;
}

void Magazin::afisare_toate_produse() const
{
    for (const auto& produs : produse)
        produs -> afisare();
}

///meniuri
void Magazin::meniu()
{
    cout << "Bun venit la Rock the Shop!!!" << endl;
    cout << "Optiunea 1: Gestiune angajati" << endl;
    cout << "Optiunea 2: Gestiune stoc-produse" << endl;
    cout << "Optiunea 3: Procesare comenzi" << endl;
    cout << "Optiunea 4: Raportare" << endl;
    cout << "Optiunea 0: Iesire" << endl;
    cout << "Introduceti optiunea: ";
}

void Magazin::meniu_angajati(Magazin& magazin)
{
    int optiune;
    do {
        cout << "Aici se face gestiunea angajatilor Rock the Shop" << endl;
        cout << "Optiunea 1: Adaugare angajat" << endl;
        cout << "Optiunea 2: Stergere angajat" << endl;
        cout << "Optiunea 3: Modificare angajat" << endl;
        cout << "Optiunea 4: Afisare date angajat" << endl;
        cout << "Optiunea 5: Afisare toti angajatii" << endl;
        cout << "Optiunea 0: Intoarcere la meniul principal" << endl;
        cout << "Introduceti optiunea: ";
        cin >> optiune;

        switch (optiune)
        {
            case 1:
                magazin.adaugare_angajat();
                break;
            case 2:
            {
                int id;
                cout << "Introduceti ID ul angajatului pe care doriti sa l stergeti: ";
                cin >> id;
                magazin.stergere_angajat(id);
                break;
            }
            case 3:
            {
                int id;
                cout << "Introduceti ID ul angajatului pe care doriti sa l modificati: ";
                cin >> id;
                magazin.modificare_angajat(id);
                break;
            }
            case 4:
            {
                int id;
                cout << "Introduceti ID ul angajatului caruia doriti sa i afisati datele: ";
                cin >> id;
                magazin.afisare_angajat(id);
                break;
            }
            case 5:
                magazin.afisare_toti_angajati();
                break;
            case 0:
                cout << "Intoarcere la meniul principal" << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
        }
    } while (optiune != 0);
}

void Magazin::meniu_produse(Magazin& magazin)
{
    int optiune;
    do {
        cout << "Aici se face gestiunea stocului(produselor) de la Rock the Shop" << endl;
        cout << "Optiunea 1: Adaugare produs" << endl;
        cout << "Optiunea 2: Stergere produs" << endl;
        cout << "Optiunea 3: Modificare produs" << endl;
        cout << "Optiunea 4: Afisare date produs" << endl;
        cout << "Optiunea 5: Afisare toate produsele" << endl;
        cout << "Optiunea 0: Intoarcere la meniul principal" << endl;
        cout << "Introduceti optiunea: ";
        cin >> optiune;
        switch (optiune)
        {
            case 1:
                magazin.adaugare_produs();
                break;
            case 2:
            {
                int id;
                cout << "Introduceti ID ul produsului pe care vreti sa l stergeti: ";
                cin >> id;
                magazin.stergere_produs(id);
                break;
            }
            case 3:
            {
                int id;
                cout << "Introduceti ID ul produsului pe care vreti sa l modificati: ";
                cin >> id;
                magazin.modificare_produs(id);
                break;
            }
            case 4:
            {
                int id;
                cout << "Introduceti ID ul produsului pe care vreti sa l afisati: ";
                cin >> id;
                magazin.afisare_produs(id);
                break;
            }
            case 5:
                magazin.afisare_toate_produse();
                break;
            case 0:
                cout << "Intoarcere la meniul principal" << endl;
                break;
            default:
                cout << "Optiune invalida!" << endl;
        }
    } while (optiune != 0);
}

///pentru procesare
void Magazin::citire_comenzi(const string& fisier)
{
    ifstream fin(fisier);
    string linie;
    while (getline(fin, linie))
    {
        istringstream a(linie);
        int id, durata;
        string data;
        float valoare;
        vector<string> discuri, vestimentare;
        string produs;

        a >> id >> data >> durata >> valoare;
        tm data_tm = Angajat::data_din_string_in_tm(data);

        while (a >> produs)
        {
            if (produs.substr(0, 2) == "CD" || produs.substr(0, 5) == "Vinil" || produs.substr(0, 12) == "Disc_vintage")
            {
                /// Produs de tip disc
                discuri.push_back(produs);
            }
            else if (produs.substr(0, 6) == "Tricou")
            {
                /// Produs de tip articol vestimentar
                vestimentare.push_back(produs);
            }
        }

        ///creez obiectul comanda si il si validez
        try
        {
            Comanda comanda(id, data_tm, durata, valoare, discuri, vestimentare);
            comanda.validare_comanda(produse); /// Validez comanda, inclusiv verificarea stocului
            comenzi_primite.push(comanda); /// Adaug comanda în coada de comenzi primite
            cout << "Comanda ID " << id << " a fost adaugata" << endl;
        }
        catch (const exception& e)
        {
            cerr << "Eroare la adaugarea comenzii: " << e.what() << "\n";
        }
    }
    fin.close();
}

bool Magazin::sunt_comenzi_in_desfasurare() const
{
    for (const auto& operator_angajat : operatori)
        if (operator_angajat -> get_nr_comenzi() > 0)
            return true; ///avem comenzi in desfasurare
    return false; ///nu avem comenzi in desfasurare
}

void Magazin::actualizare_stoc(const Comanda& comanda)
{
    ///actualizam stocul de produse pentru discuri
    for (const auto& disc : comanda.get_discuri())
        for (auto& produs : produse)
            if (produs -> get_denumire() == disc && produs -> get_nr_produse() > 0)
            {
                produs -> scade_nr_produse(1);
                break;
            }

    ///actualizam stocul de produse pentru rticole vestimentare
    for (const auto& vest : comanda.get_vestimentare())
        for (auto& produs : produse)
            if (produs -> get_denumire() == vest && produs -> get_nr_produse() > 0)
            {
                produs -> scade_nr_produse(1);
                break;
            }
}

void Magazin::procesare_comenzi()
{
    while (!comenzi_primite.empty() || sunt_comenzi_in_desfasurare())
    {
        while(!comenzi_primite.empty()) ///aici atribui comenzile catre operatori
        {
            int minim = 3;
            Operator* operator_angajat = nullptr;
            for(auto& operator_angajatt:operatori)
                if(operator_angajatt -> get_nr_comenzi() < minim) ///caut operatorul cu cele mai putine comenzi
                {
                    minim = operator_angajatt->get_nr_comenzi();
                    operator_angajat=operator_angajatt;
                }
            if(minim==3)
            {
                cout << "Niciun angajat nu poate procesa comenzi" << endl;
                cout << "---------------------------------";
            }
            else
            {
                cout << "Minimul este: " << minim << ", iar operatorul : "<< operator_angajat -> get_nume() << " are numarul de comenzi: "<< operator_angajat -> get_nr_comenzi() << "\n\n\n";
                Comanda comanda = comenzi_primite.front(); ///trimit primul element din comenzi_plasate catre comanda
                comenzi_primite.pop();
                try
                {
                    operator_angajat -> adaugare_comanda(comanda);
                    actualizare_stoc(comanda); ///reducem produsele de pe stoc
                    cout << "Comanda ID " << comanda.getId() << " atribuita operatorului " << operator_angajat -> get_nume() << "\n\n";
                } catch (const exception& e) {
                    cout << "Eroare la atribuirea comenzii: " << e.what() << "\n";
                }
            }
            for(auto& operatorr : operatori)
            {
                if(operatorr -> get_nr_comenzi() > 0)
                    operatorr -> procesare_comanda();
                else
                    cout << "Operatorul: " << operatorr -> get_nume() << " nu are comenzi de procesat" << endl;
            }
            cout << "---------------------------------\n";
        }

        for(auto& operatorr : operatori)
        {
            if(operatorr -> get_nr_comenzi() > 0)
                operatorr -> procesare_comanda();
            else
                cout << "Operatorul: " << operatorr -> get_nume() << " nu are comenzi de procesat" << endl;
        }
         cout << "---------------------------------" << endl;
    }
}

void Magazin::angajat_cele_mai_multe_comenzi()
{
    int maxim = 0;
    Operator *aux = nullptr;
    for(auto & operatorr : operatori)
        if(operatorr->get_comenzi_totale() > maxim)
        {
            maxim = operatorr -> get_comenzi_totale();
            aux = operatorr;
        }
    ofstream fisier("raport1.csv");
    fisier << "Nume, Maxim_Comenzi \n";
    fisier << aux -> get_nume() <<"," << maxim << endl;
}

void Magazin::top_valoare_comenzi()
{
    if (operatori.size() < 3)
    {
        cout << "Nu avem destui operatori" << endl;
        return;
    }

    sort(operatori.begin(), operatori.end(), [](Operator* a, Operator* b)
        {
        return a -> get_val_totala_comenzi() > b -> get_val_totala_comenzi();
        });

    ofstream fisier("raport2.csv");
    fisier<< "Nume, Valoare Totala Comenzi\n";

    for (size_t i = 0; i < 3 && i < operatori.size(); i++)
        fisier << operatori[i] -> get_nume() << "," << operatori[i] -> get_val_totala_comenzi() << "\n";
}

void Magazin::top_3_salariu()
{
    int anul_curent = 2025;
    if (operatori.size() < 3)
    {
        cout << "Nu avem destui operatori" << endl;
        return;
    }

    sort(angajati.begin(), angajati.end(), [anul_curent](Angajat* a, Angajat* b)
        {
        return a -> salariu(anul_curent) > b -> salariu(anul_curent);
        });

    vector<Angajat*> primii3(angajati.begin(), angajati.begin() + 3);

    sort(primii3.begin(), primii3.end(), [](Angajat* a, Angajat* b)
        {
        if (a -> get_nume() != b -> get_nume())
            return a -> get_nume() < b -> get_nume();
        return a -> get_prenume() < b -> get_prenume();
        });

    ofstream fisier("raport3.csv");
    fisier << "Nume Prenume, Salariu\n";

    for (size_t i = 0; i < primii3.size(); i++)
        {
        fisier << primii3[i]->get_nume() << " " << primii3[i]->get_prenume() << "," << primii3[i]->salariu(anul_curent) << "\n";
        }
}
