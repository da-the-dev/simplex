#include <iostream>

using namespace std;

#include "matrix.h"

using namespace std;

int main() {
  Matrix m(10, 2);

  m(0, 1) = 1;

  cout << m << endl;

  return 0;
}
