#pragma once
#include <iostream>
using namespace std;
/**
设计:
类模板 构造函数 拷贝构造函数 << []  重载=操作符
 a2=a1
**/

template <typename T>
class MyVector {
  friend ostream& operator<<(ostream& os, const MyVector<T>& myVec) {
    for (int i = 0; i < myVec.m_length; i++) {
      os << myVec.m_datas[i] << " ";
    }
    return os;
  }
public:
  MyVector(int length);
  MyVector(const MyVector<T>& myVec);
  ~MyVector();
  MyVector<T>& operator=(const MyVector<T>& myVec);
  T& operator[](int index);
  int length() const;
private:
  int m_length;
  T *m_datas;
protected:
};
