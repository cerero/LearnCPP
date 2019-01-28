#include "MyString.h"
#include <iostream>
using namespace std;

int main(int argc, char **argv) {
  MyString str1;
  MyString str2("abcd");
  MyString str3("1234");

  cout << "str1: " << str1 << endl;
  cout << "str2: " << str2 << endl;
  cout << "str3: " << str3 << endl;

  str1 = str2;
  cout << "after str1 = str2: " << str1 << endl;
  cout << "check str1 == str2: " << boolalpha << (str1 == str2);
  cout << endl;
  cout << "check str2 == str3: " << boolalpha << (str2 == str3);
  cout << endl;
  cout << "check str2 != str3: " << boolalpha << (str2 != str3);
  cout << endl;
  cout << "check str2 > str3: " << boolalpha << (str2 > str3);
  cout << endl;
  cout << "check str2 < str3: " << boolalpha << (str2 < str3);
  cout << endl;
  return 0;
}
