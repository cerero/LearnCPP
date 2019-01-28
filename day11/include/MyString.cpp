#include <iostream>
#include "MyString.h"
#include <cstring>

//int m_length;
// char *m_ptr_chr;

MyString::MyString() {
  m_length = 0;
  m_ptr_chr = NULL;
}

MyString::MyString(const char *chr) {
  m_length = strlen(chr);
  m_ptr_chr = new char[m_length + 1];

  if (m_ptr_chr) {
    strcpy(m_ptr_chr, chr);
  }
}
MyString::MyString(const MyString& myString) {
  m_length = myString.m_length;
  m_ptr_chr = new char[m_length + 1];

  if (m_ptr_chr) {
    strcpy(m_ptr_chr, myString.m_ptr_chr);
  }
}
MyString::~MyString() {
  if (m_ptr_chr) {
    delete[] m_ptr_chr;
    m_ptr_chr = NULL;
    m_length = 0;
  }
}
std::ostream& operator<<(std::ostream& os, const MyString& myString) {
  if (myString.m_ptr_chr) {
      os << myString.m_ptr_chr;
  }
  return os;
}
std::istream& operator>>(std::istream& is, const MyString& myString) {
  return is;
}
bool MyString::operator==(const MyString& myString) {
  return m_ptr_chr && myString.m_ptr_chr && m_length == myString.m_length && (memcmp(m_ptr_chr, myString.m_ptr_chr, m_length) == 0);
}
bool MyString::operator!=(const MyString& myString) {
  return !(*this == myString);
}
bool MyString::operator>(const MyString& myString) {
  if (m_ptr_chr && myString.m_ptr_chr) {
    return strcmp(m_ptr_chr, myString.m_ptr_chr) > 0;
  } else {
    return false;
  }
}

bool MyString::operator<(const MyString& myString) {
  if (m_ptr_chr && myString.m_ptr_chr) {
    return strcmp(m_ptr_chr, myString.m_ptr_chr) < 0;
  } else {
    return false;
  }
}

const MyString& MyString::operator=(const MyString& myString) {
  if (m_ptr_chr) {
    delete[] m_ptr_chr;
    m_ptr_chr = NULL;
    m_length = 0;
  }

  m_length = myString.m_length;
  m_ptr_chr = new char[m_length + 1];
  if (m_ptr_chr) {
    strcpy(m_ptr_chr, myString.m_ptr_chr);
  }

  return myString;
}
