#include <iostream>
#include "CPolynomial.h"
#include "CExponential.h"

using namespace std;

int main() {
    // Test Polynomial
    double coeffs[] = {1.0, 2.0, 3.0};
    Polynomial p(coeffs, 3);

    cout << "=== Polynomial Test ===" << endl;
    p.Dump();

    double x = 2.0;
    cout << "Polynomial value at x = " << x << ": " << p.GetValue(x) << endl;

    Function* f = &p;
    cout << "Function pointer call (Polynomial) at x = " << x << ": " << f->GetValue(x) << endl;

    // Test Exponential
    Exponential e(2.0, 3.0, 0.5); // f(x) = 3 * 2^(0.5 * x)
    cout << "\n=== Exponential Test ===" << endl;
    e.Dump();

    double x2 = 4.0;
    cout << "Exponential value at x = " << x2 << ": " << e.GetValue(x2) << endl;

    Function* f2 = &e;
    cout << "Function pointer call (Exponential) at x = " << x2 << ": " << f2->GetValue(x2) << endl;

    // Test copy and equality
    Exponential e2 = e;
    if (e2 == e)
        cout << "Exponential e2 is equal to e." << endl;
    else
        cout << "Exponential e2 is different from e." << endl;

    return 0;
}
