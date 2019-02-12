#include <iostream>
using namespace std;


int main(int argc, char **argv) {

  int a = 1000;
  char c = 'a';

  a = static_cast<int>(c);

  char c_ptr[] = "I love sugar";
  int *i_ptr = NULL;

  i_ptr = reinterpret_cast<int *>(c_ptr);
  cout << "c_ptr: " << c_ptr << endl;
  cout << "i_ptr: " << i_ptr << endl;

  return 0;
}
