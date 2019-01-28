#include "Array.h"
#include <cstring>

Array::Array(int length) : datas(NULL), len(0) {
  len = length;
  datas = new int[len];
}

Array::Array(const Array& array) {
  len = array.len;
  datas = new int[len];
  memcpy(datas, array.datas, len * sizeof(int));
}

Array::~Array() {
  if (datas) {
    delete[] datas;
    datas = NULL;
    len = 0;
  }
}

int Array::getData(int index) {
  if (index < len) {
    return datas[index];
  } else
    return 0;
}

void Array::setData(int index, int data) {
  if (index < len) {
    datas[index] = data;
  }
}

int Array::length() {
  return len;
}

int& Array::operator[](int index) {
  return datas[index];
}

Array& Array::operator=(Array& array) {
  if (datas) {
    delete[] datas;
    datas = NULL;
    len = 0;
  }
  len = array.len;
  datas = new int[array.len];
  memcpy(datas, array.datas, len * sizeof(int));
  return array;
}

bool Array::operator==(Array& array) {
  return datas && array.datas && len == array.len && (memcmp(datas, array.datas, len) == 0);
}

bool Array::operator!=(Array& array) {
  return !datas || !array.datas || len != array.len || (memcmp(datas, array.datas, len) != 0);
}
