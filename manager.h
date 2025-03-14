#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

#include "angajat.h"

class Manager : public Angajat
{

public:
    Manager(string nume = "", string prenume = "", const string& CNP = "", const tm& data_angajare = {});

    void citire() override;

    void afisare() const override;

    float salariu(int anul_curent) const;
};

#endif // MANAGER_H_INCLUDED
