#include "Array.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  Array a1(10);
  for (int i = 0; i < a1.length(); i++) {
    a1.setData(i, i);
  }

  for (int i = 0; i < a1.length(); i++) {
    cout << "a1 " << i << ":" << a1.getData(i) << endl;
  }

  cout << "Copy constructor" << endl;
  Array a2 = a1;
  for (int i = 0; i < a1.length(); i++) {
    cout << "a2 " << i << ":" << a2.getData(i) << endl;
  }
  cout << "====================" << endl;

  Array a3(5);
  for (int i = 0; i < a3.length(); i++) {
    a3[i] = i + 1;
  }
  for (int i = 0; i < a3.length(); i++) {
    cout << "a3 " << i << ":" << a3[i] << endl;
  }

  Array a4(10);
  a4 = a3;
  if (a3 == a4) {
    cout << "a3 == a4" << endl;
  }

  Array a5(5);
  if (a3 != a5) {
    cout << "a3 != a4" << endl;
  }

  return 0;
}
