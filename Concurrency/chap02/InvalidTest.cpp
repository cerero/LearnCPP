#include <iostream>
#include <thread>

//线程访问了无效内存

struct func {
  int& i;
  func(int& i_):i(i_) {

  }

  void operator()() {
    for (unsigned j = 0; j < 1000000; j++) {
      std::cout << j << ":" << i << "\n";
    }
  }
};

void oops() {
  int some_local_value = 0;
  func my_func(some_local_value);
  std::thread my_thread(my_func);
  my_thread.detach();   //不等待my_thread执行完毕，oops函数返回后，some_local_value就会失效，导致my_thread线程的i变量无效
  //my_thread.join();   //等待my_thread执行完毕，这样内部的i变量就不会有问题了
}

int main() {
  oops();
  return 0;
}
