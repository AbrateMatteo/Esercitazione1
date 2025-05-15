#include "CExponential.h"

Exponential::Exponential() {
    b_coeff = 2.0; // default base > 0
    k_coeff = 1.0;
    c_coeff = 1.0;
}

Exponential::Exponential(double b, double k, double c) {
    if (b <= 0) {
        ErrorMessage("Constructor: base b must be > 0. Setting b = 2.0");
        b = 2.0;
    }
    b_coeff = b;
    k_coeff = k;
    c_coeff = c;
}

Exponential::Exponential(const Exponential& e) {
    b_coeff = e.b_coeff;
    k_coeff = e.k_coeff;
    c_coeff = e.c_coeff;
}

Exponential::~Exponential() {}

Exponential& Exponential::operator=(const Exponential& e) {
    if (this != &e) {
        b_coeff = e.b_coeff;
        k_coeff = e.k_coeff;
        c_coeff = e.c_coeff;
    }
    return *this;
}

bool Exponential::operator==(const Exponential& e) {
    return (b_coeff == e.b_coeff && k_coeff == e.k_coeff && c_coeff == e.c_coeff);
}

double Exponential::GetValue(double in) const {
    return k_coeff * pow(b_coeff, c_coeff * in);
}

void Exponential::Dump() {
    cout << "Exponential function: f(x) = " << k_coeff << " * " << b_coeff << "^( " << c_coeff << " * x )" << endl;
}

void Exponential::SetParameters(double b, double k, double c) {
    if (b <= 0) {
        ErrorMessage("SetParameters: base b must be > 0. No changes made.");
        return;
    }
    b_coeff = b;
    k_coeff = k;
    c_coeff = c;
}

void Exponential::ErrorMessage(const char* string) {
    cout << endl << "ERROR -- Exponential -- " << string << endl;
}

void Exponential::WarningMessage(const char* string) {
    cout << endl << "WARNING -- Exponential -- " << string << endl;
}
