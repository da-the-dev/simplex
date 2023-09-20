#include "matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int height, int width) : height(height), width(width) {
  matrix = new double *[height];
  for (int i = 0; i < height; i++) {
    matrix[i] = new double[width];
  }
}

Matrix Matrix::operator+(const Matrix &matrixEntity) const {
  if ((matrixEntity.height == height) && (matrixEntity.width == width)) {
    Matrix newMatrix(height, width);
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        newMatrix.matrix[i][j] = matrix[i][j] + matrixEntity.matrix[i][j];
      }
    }
    return newMatrix;
  } else {
    cout << "Error: the dimensional problem occurred" << endl;
    return {0, 0};
  }
}

Matrix Matrix::operator-(const Matrix &matrixEntity) const {
  if ((matrixEntity.height == height) && (matrixEntity.width == width)) {
    Matrix newMatrix(height, width);
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        newMatrix.matrix[i][j] = matrix[i][j] - matrixEntity.matrix[i][j];
      }
    }
    return newMatrix;
  } else {
    cout << "Error: the dimensional problem occurred" << endl;
    return {0, 0};
  }
}

Matrix Matrix::operator*(const Matrix &matrixEntity) const {
  if (width == matrixEntity.height) {
    Matrix newMatrix(height, matrixEntity.width);
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < matrixEntity.width; j++) {
        double temp = 0;
        for (int k = 0; k < width; k++) {
          abs(temp + matrix[i][k] * matrixEntity.matrix[k][j]) >= 1e-10
              ? temp += matrix[i][k] * matrixEntity.matrix[k][j]
              : temp = 0;
        }
        newMatrix.matrix[i][j] = temp;
      }
    }
    return newMatrix;
  } else {
    cout << "Error: the dimensional problem occurred" << endl;
    return {0, 0};
  }
}

void Matrix::operator=(const Matrix &matrixEntity) {
  if (matrixEntity.height == height && matrixEntity.width == 1 ||
      height == 0 && width == 0) {
    this->height = matrixEntity.height;
    this->width = matrixEntity.width;
    this->matrix = matrixEntity.matrix;
  }
}

// TODO: WTF???
// Matrix T() const {
//     Matrix matrixEntity(width, height);
//     for (int i = 0; i < height; i++) {
//         for (int j = 0; j < width; j++) {
//             matrixEntity.matrix[j][i] = this->matrix[i][j];
//         }
//     }
//     return matrixEntity;
// }

void Matrix::permute(int first, int second) {
  if (first < height && second < height) {
  }
  double *temp = matrix[first];
  matrix[first] = matrix[second];
  matrix[second] = temp;
}
void Matrix::rowSubtract(int first, int second, double coef) {
  for (int i = 0; i < width; i++) {
    matrix[second][i] -= matrix[first][i] * coef;
    abs(matrix[second][i]) < 1e-10 ? matrix[second][i] = 0
                                   : matrix[second][i] = matrix[second][i];
  }
}

double Matrix::getValue(int i, int j) {
  double a = matrix[i][j];
  return (a);
}

