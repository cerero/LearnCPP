#ifndef _ARRAY_HEADER_
#define _ARRAY_HEADER_

class Array {
private:
  int *datas;
  int len;
public:
  Array(int length);
  Array(const Array& array);
  ~Array();
  int getData(int index);
  void setData(int index, int data);
  int length();

  int& operator[](int index);
  Array& operator=(Array& array);
  bool operator==(Array& array);
  bool operator!=(Array& array);
};

#endif
