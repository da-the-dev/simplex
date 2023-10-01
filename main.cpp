#include <iostream>

#include "matrix.h"
#include "simplex.h"

using namespace std;

int main() {
    int variables;  // number of variables
    int constraints;  // number of constraints
    cin >> variables;
    cin >> constraints;

    Matrix C(1, variables);
    cin >> C;

    Matrix A(constraints, variables);
    cin >> A;

    Matrix b(constraints, 1);
    cin >> b;

    int approximation;
    cin >> approximation;

    simplex(C, A, b, approximation, variables, constraints);

    return 0;
}
