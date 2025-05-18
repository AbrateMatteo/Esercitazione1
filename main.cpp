#include <iostream>
#include "CPolynomial.h"
#include "CExponential.h"
#include "CPower.h"

int main() {
    std::cout << "--- TEST POLYNOMIAL ---\n";

    Polynomial p1;
    double coeffs[] = {1.0, -2.0, 3.0}; // 1 - 2x + 3x^2
    p1.SetPolynomial(coeffs, 3);

    std::cout << "p1 (after SetPolynomial): ";
    p1.Dump();

    std::cout << "p1(2.0) = " << p1.GetValue(2.0) << "\n";

    Polynomial p2(p1); // copy constructor
    Polynomial p3;
    p3 = p1;           // assignment operator

    Polynomial p_sum = p1 + p2;

    std::cout << "p2 (copy of p1): ";
    p2.Dump();
    std::cout << "p3 (assigned from p1): ";
    p3.Dump();
    std::cout << "p1 + p2: ";
    p_sum.Dump();

    std::cout << "p1 == p2: " << (p1 == p2 ? "true" : "false") << "\n";

    std::cout << "\n--- TEST EXPONENTIAL ---\n";

    Exponential e1;
    e1.SetParameters(5.0, 3.0, 0.5); // 3 * 5^(0.5 * x)

    std::cout << "e1 (after SetParameters): ";
    e1.Dump();
    std::cout << "e1(2.0) = " << e1.GetValue(2.0) << "\n";

    Exponential e2(e1); // copy constructor
    Exponential e3;
    e3 = e1;            // assignment

    std::cout << "e2 (copy of e1): ";
    e2.Dump();
    std::cout << "e3 (assigned from e1): ";
    e3.Dump();
    std::cout << "e2 == e3: " << (e2 == e3 ? "true" : "false") << "\n";

    std::cout << "\n--- TEST POWER ---\n";

    Power pow1;
    pow1.SetParameters(2.5, 4.0); // 4 * x^2.5

    std::cout << "pow1 (after SetParameters): ";
    pow1.Dump();
    std::cout << "pow1(2.0) = " << pow1.GetValue(2.0) << "\n";

    Power pow2(pow1); // copy
    Power pow3;
    pow3 = pow1; // assignment

    std::cout << "pow2 (copy of pow1): ";
    pow2.Dump();
    std::cout << "pow3 (assigned from pow1): ";
    pow3.Dump();
    std::cout << "pow2 == pow3: " << (pow2 == pow3 ? "true" : "false") << "\n";

    return 0;
}
