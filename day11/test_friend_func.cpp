#include <iostream>
using namespace std;

class A;
void printA(A& a);

class A {
public:
  A(int a) {
    this->a = a;
  }
  friend void printA(A& a);
private:
  int a;
};

void printA(A& a) {
  cout << "A::a = " << a.a << endl;
}

int main(int argc, char **argv) {
  A a(10);
  printA(a);
  return 0;
}
