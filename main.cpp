#include <iostream>
#include "angajat.h"
#include "manager.h"
#include "operator.h"
#include "asistent.h"
#include "vinil.h"
#include "CD.h"
#include "discuri.h"
#include "discuri_vintage.h"
#include "vestimentatie.h"
#include "magazin.h"

using namespace std;

int main()
{
    Magazin magazin;
    magazin.verificare_angajati();
    magazin.verificare_produse();
    int optiune;
    do {
        magazin.meniu();
        cin >> optiune;
        switch (optiune)
        {
            case 1:
                magazin.meniu_angajati(magazin);
                break;
            case 2:
                magazin.meniu_produse(magazin);
                break;
            case 3:
                magazin.citire_comenzi("comenzi.txt");
                magazin.procesare_comenzi();
                break;
            case 4:
                magazin.angajat_cele_mai_multe_comenzi();
                magazin.top_valoare_comenzi();
                magazin.top_3_salariu();
                break;
            case 0:
                cout << "Iesire\n";
                break;
            default:
                cout << "Optiune invalida!" << endl;
        }
    } while (optiune != 0);
}
