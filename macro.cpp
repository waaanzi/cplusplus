#include <iostream>
#include <cassert>

struct A {
  void show() {
    std::cout << "show" << std::endl;
  }
};

#define SHOW \
  std::cout << "SHOW" << std::endl; \
  assert(a != NULL); \
  a->show();

void func1(A* a) {
  SHOW
}

void func2(A* a) {
  SHOW
}

int main() {
  A a;
  func1(&a);
  system("pause");
  return 0;
}

#define X \
  1