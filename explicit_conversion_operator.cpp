/* 显示转换操作符 */

namespace demo1 {
class A {
 public:
  operator bool() {
    return true;
  }
};
}

namespace demo2 {
class A {
 public:

  // 显示转换操作符
  explicit operator bool() {
    return true;
  }
};
}

#include <iostream>

void func(bool b) {}

int main() {
  {
    demo1::A a;
    demo1::A a1;

    // 通过
    bool b1 = a;
    func(a);

    // 通过
    if (a) {}
    if (!a) {}
    if (a && a1) {}
    int n = a ? 1 : 2;
    while (a) {}
  }

  {
    demo2::A a;
    demo2::A a1;

    // error
    // bool b2 = a;
    // func(a);

    // 作为条件用, explicit operator bool能通过
    if (a) {}
    if (!a) {}
    if (a && a1) {}
    int n = a ? 1 : 2;
    while (a) {}
  }
  return 0;
}