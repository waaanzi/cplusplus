#include <iostream>
#include <utility> // declval

struct A {
  A() {std::cout << "A()" << std::endl;}
  int f() {return 1;};
};

struct B {
  float f() {return 2;};
 private:
  B() {std::cout << "B()" << std::endl;}
};

struct C {
  C() = delete;
  double f() { return 3; };
};

int main() {
  // A有默认构造
  std::cout << "decltype(std::declval<A>().f()) type: "
            << typeid(decltype(std::declval<A>().f())).name() << std::endl;
  decltype(A().f()) a = 11;

  // B默认构造为私有
  std::cout << "decltype(std::declval<B>().f()) type: " 
            << typeid(decltype(std::declval<B>().f())).name() << std::endl;
  decltype(std::declval<B>().f()) b = 22;

  // C无默认构造
  std::cout << "decltype(std::declval<C>().f()) type: "
            << typeid(decltype(std::declval<C>().f())).name() << std::endl;
  decltype(std::declval<C>().f()) c = 33;

  std::cin.get();
  return 0;
}