#include <iostream>

using namespace std;

#include "matrix.h"

using namespace std;

int main() {
  Matrix m(10, 10);;

  m.matrix[0][0] = -100;

  cout << m.matrix[0][0] << endl;

  return 0;


}
