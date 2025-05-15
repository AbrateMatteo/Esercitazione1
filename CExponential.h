#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

#include <iostream>
#include <cmath>
#include "CFunction.h"

using namespace std;

class Exponential : public Function {
private:
    double b_coeff;  // base > 0
    double k_coeff;  // multiplicative constant
    double c_coeff;  // exponent multiplier

public:
    // Costruttori e distruttore
    Exponential();
    Exponential(double b, double k, double c);
    Exponential(const Exponential& e);
    ~Exponential();

    // Operatori
    Exponential& operator=(const Exponential& e);
    bool operator==(const Exponential& e);

    // Metodi
    double GetValue(double in) const override;
    void Dump() override;

    void SetParameters(double b, double k, double c);

    // Messaggi di errore
    void ErrorMessage(const char* string);
    void WarningMessage(const char* string);
};

#endif
