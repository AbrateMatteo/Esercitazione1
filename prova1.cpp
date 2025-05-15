#include <iostream>
#include "CPolynomial.h"

using namespace std;

int main() {
    // Coefficienti del polinomio: 1 + 2x + 3x^2
    double coeffs[] = {1.0, 2.0, 3.0};

    // Creo un oggetto Polynomial
    Polynomial p(coeffs, 3);

    // Testo il metodo Dump (eredita da Function virtuale pura)
    cout << "Polynomial Dump:" << endl;
    p.Dump();

    // Testo il metodo GetValue (eredita da Function virtuale pura)
    double x = 2.0;
    double result = p.GetValue(x);
    cout << "Polynomial evaluated at x = " << x << ": " << result << endl;

    // Test puntatore alla classe base Function (polimorfismo)
    Function* f = &p;
    cout << "Calling GetValue via Function pointer at x = " << x << ": " << f->GetValue(x) << endl;
    f->Dump();

    // Test del copy constructor
    Polynomial q(p);
    cout << "Copy of polynomial Dump:" << endl;
    q.Dump();

    // Test operatore di assegnazione
    Polynomial r;
    r = p;
    cout << "Assignment operator Dump:" << endl;
    r.Dump();

    // Test operatore di uguaglianza
    if (p == q)
        cout << "Polynomials p and q are equal." << endl;
    else
        cout << "Polynomials p and q are different." << endl;

    // Test reset
    r.Reset();
    cout << "After reset, r is:" << endl;
    r.Dump();

    return 0;
}

