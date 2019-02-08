#include "MyVector.h"
#include <iostream>
using namespace std;

// template <typename T>
// ostream& operator<<(ostream& os, const MyVector<T>& myVec) {
//   for (int i = 0; i < myVec.m_length; i++) {
//     os << myVec[i] << " ";
//   }
// }

template <typename T>
MyVector<T>::MyVector(int length) {
  m_length = length;
  m_datas = new T [length];
}

template <typename T>
MyVector<T>::MyVector(const MyVector<T>& myVec) {
  m_length = myVec.m_length;
  m_datas = new T[m_length];
  for (int i = 0; i < m_length; i++) {
    m_datas[i] = myVec.m_datas[i];
  }
}

template <typename T>
MyVector<T>::~MyVector() {
  if (m_datas) {
    delete [] m_datas;
    m_datas = NULL;
    m_length = 0;
  }
}

template <typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& myVec) {
  if (m_datas) {
    delete [] m_datas;
    m_datas = NULL;
    m_length = 0;
  }

  m_length = myVec.m_length;
  m_datas = new T[myVec.m_length];
  for (int i = 0; i < myVec.m_length; i++) {
    m_datas[i] = myVec.m_datas[i];
  }

  return *this;
}

template <typename T>
T& MyVector<T>::operator[](int index) {
  return m_datas[index];
}

template <typename T>
int MyVector<T>::length() const {
  return m_length;
}
