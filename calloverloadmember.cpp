#include <iostream>
#include <thread>
#include <functional>

class A {
 public:
  void func() {
    std::cout << "func()" << std::endl;
  }
  void func(int val) {
    std::cout << "func(int): " << val << std::endl;
  }
};

int main() {
  A a;
  // std::thread t(std::bind(&A::func, a)); // error

  // method 1
  using Func = void(A::*)();
  Func f1 = &A::func;
  std::thread t1(std::bind(f1, a));
  t1.join();

  // method 2
  void(A::*f2)(int) = &A::func;
  std::thread t2(std::bind(f2, a, 100));
  t2.join();
  std::cin.get();
  return 0;
}