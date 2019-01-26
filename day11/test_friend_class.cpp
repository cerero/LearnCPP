#include <iostream>
using namespace std;

class A {
public:
  A(int a) {
    this->a = a;
  }
  friend class B;
private:
  int a;
};

class B {
public:
  B(int val): a(val){}
  void printA() {
    cout << "A::a = " << a.a << endl;
  }
private:
  A a;
};

int main(int argc, char **argv) {
  B b(10);
  b.printA();
  return 0;
}
