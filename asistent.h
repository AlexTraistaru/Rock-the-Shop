#ifndef ASISTENT_H_INCLUDED
#define ASISTENT_H_INCLUDED

#include "angajat.h"

class Asistent : public Angajat
{
public:
    Asistent(string nume = "", string prenume = "", const string& CNP = "", const tm& data_angajare = {});

    void citire() override;

    void afisare() const override;

    float salariu(int anul_curent) const;
};

#endif
