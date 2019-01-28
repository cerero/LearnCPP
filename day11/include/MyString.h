#ifndef _MY_STRING_HEADER_
#define _MY_STRING_HEADER_
#include <iostream>
/**
MyString a
MyString a("ddd")
MyString a = b

<< >> != == > < =
**/

class MyString {
private:
  int m_length;
  char *m_ptr_chr;
public:
  MyString();
  MyString(const char *chr);
  MyString(const MyString& myString);
  ~MyString();
  friend std::ostream& operator<<(std::ostream& os, const MyString& myString);
  friend std::istream& operator>>(std::istream& is, const MyString& myString);
  bool operator==(const MyString& myString);
  bool operator!=(const MyString& myString);
  bool operator>(const MyString& myString);
  bool operator<(const MyString& myString);
  const MyString& operator=(const MyString& myString);
};
#endif
