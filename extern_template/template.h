#include <iostream>

template <typename T>
class A {};

template <typename T>
class B {
 public:
  static void f_m(T t) {
    std::cout << "B::f_m t: " << t << std::endl;
  };
};
template <typename T>
static void f1(T t) {
  std::cout << "static f1" << std::endl;
};

template <typename T>
void f2(T t) {
  std::cout << "f2" << std::endl;
};
