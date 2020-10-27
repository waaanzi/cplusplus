#include "template.h"

void f11() {
  A<int> a;
  f1(1);
  std::cout << "f3" << std::endl;
}

void f22() {
  f2(1);
  std::cout << "f22" << std::endl;
}

void fm() {
  B<int>::f_m(1);
  std::cout << "fm" << std::endl;
}