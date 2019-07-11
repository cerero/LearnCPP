#include <iostream>
#include <thread>

class background_task {
public:
  void operator()() const {
    std::cout << "this is bg task.\n";
  }
};

int main(int argc, char **argv) {
  background_task task;
  std::thread t(task);
  t.join();
  return 0;
}
