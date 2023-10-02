#include "matrix.h"
#include <istream>
#include <cfloat>
#include <iomanip>

using namespace std;

Matrix createTable(Matrix A, Matrix b, Matrix C) {
    Matrix table(A.height + 1, A.width + A.height + 1);
    for (int k = 0; k < C.width; k++) {
        table.matrix[0][k] = -1 * C.matrix[0][k];
    }
    for (int k = C.width; k < table.width; k++) {
        table.matrix[0][k] = 0;
    }
    for (int i = 1; i < A.height + 1; i++) {
        for (int j = 0; j < A.width; j++) {
            table.matrix[i][j] = A.matrix[i - 1][j];
        }
        for (int j = A.width; j < table.width - 1; j++) {
            if (i - 1 == j - A.width) {
                table.matrix[i][j] = 1;
            } else {
                table.matrix[i][j] = 0;
            }
        }
        table.matrix[i][table.width - 1] = b.matrix[i - 1][0];
    }
    return table;
}

int getPivotColumn(Matrix table) {
    double min = table.matrix[0][0];
    int index = 0;
    for (int i = 1; i < table.width - 1; i++) {
        if (table.matrix[0][i] < min) {
            min = table.matrix[0][i];
            index = i;
        }
    }
    if (min < 0) {
        return index;
    }
    return -1;
}

int getPivotRow(Matrix table, int pivotColumn) {
    double min = DBL_MAX;
    int index = 0;
    for(int i = 1; i < table.height; i++) {
        double rage = table.matrix[i][table.width - 1] / table.matrix[i][pivotColumn];
        if (rage < min && rage > 0) {
            min = rage;
            index = i;
        }
    }
    if (index == 0) {
        cout << "The method is not applicable!";
        exit(0);
    }
    return index;
}

void iteration(Matrix table, Matrix basis, int a) {
    int pivotColumn = getPivotColumn(table);
    if (pivotColumn == -1) {
        cout << "Maximum value of the objective function: " << fixed << setprecision(a) << table.matrix[0][table.width - 1] << endl;
        for (int i = 0; i < basis.height; i++) {
            if (basis.matrix[i][0] <= basis.height) {
                cout << "x" << basis.matrix[i][0] << " = " << fixed << setprecision(a)  << table.matrix[i + 1][table.width - 1] << endl;
            }
        }
        return;
    }
    int pivotRow = getPivotRow(table, pivotColumn);

    basis.matrix[pivotRow - 1][0] = pivotColumn + 1;
    double pivotCoeff = table.matrix[pivotRow][pivotColumn];
    for (int j = 0; j < table.width; j++) {
        table.matrix[pivotRow][j] = table.matrix[pivotRow][j] / pivotCoeff;
    }
    for (int i = 0; i < table.height; i++) {
        if (i == pivotRow) {
            continue;
        }
        double coeff = table.matrix[i][pivotColumn];
        for (int j = 0; j < table.width; j++) {
            table.matrix[i][j] -= table.matrix[pivotRow][j] * coeff;
        }
    }

    iteration(table, basis, a);
}

void simplex(Matrix C, Matrix A, Matrix b, int approximation, int variables, int constraints) {
    Matrix Table = createTable(A, b, C);

    Matrix basis(constraints, 1);
    for (int i = 0; i < constraints; i++) {
        basis.matrix[i][0] = variables + 1 + i;
    }

    iteration(Table, basis, approximation);
}

