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

  return 0;
}
