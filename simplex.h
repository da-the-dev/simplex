#ifndef SIMPLEX_H
#define SIMPLEX_H

#include "matrix.h"
#include <iostream>

using namespace std;

Matrix createTable(Matrix A, Matrix B, Matrix C);
int getPivotColumn(Matrix table);
int getPivotRow(Matrix table, int pivotColumn);
void iteration(Matrix table, Matrix basis, int a);
void simplex(Matrix C, Matrix A, Matrix b, int approximation, int variables, int constraints);

#endif // !SIMPLEX_H
