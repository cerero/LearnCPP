#include <iostream>
using namespace std;

class Test {
private:
  //global friend function
  friend ostream& operator<<(ostream& os, Test& test);
  int a, b;
public:
  Test(int a, int b) {
    this->a = a;
    this->b = b;
  }

  //member function: prefix ++Test
  Test& operator++() {
    this->a++;
    this->b++;
    return *this;
  }

  //member function: subfix Test++
  Test operator++(int) {
    Test tmp = *this;
    this->a++;
    this->b++;
    return tmp;
  }
};

ostream& operator<<(ostream& os, Test& test) {
  os << "a: " << test.a << " b: " << test.b;
  return os;
}

int main(int argc, char **argv) {
  Test test(1,2);
  cout << test << endl;
  Test tmp = test++;
  cout << "after subfix++ " << test << endl << "tmp " << tmp << endl;

  ++test;
  cout << "after prefix++ " << test << endl;

  return 0;
}
