#include "Array.h"
#include <cstring>

Array::Array(int length) : len(0), datas(NULL){
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
