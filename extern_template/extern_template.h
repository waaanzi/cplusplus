#pragma once

#include "template.h"

extern template class A<int>;
extern template void B<int>::f_m(int);

// extern template void f1<int>(int); error

extern template void f2<int>(int);

void f() {
  f2(1);
  std::cout << "f4" << std::endl;
}
