/*
委派构造：就是指委派函数将构造的任务派给了目标构造函数来完成这样一种类构造的方式。
C++11中的委派构造函数是在构造函数的初始化列表位置进行构造的、委派的
“基准版本”的构造函数称为目标构造函数，调用“基准版本”的构造函数称为委派构造函数
注意：
委派构造函数不能有初始化列表
构造函数既可以同时是目标构造函数和委派构造函数
目标构造函数中的异常可以在委派构造函数中捕获
*/

#include <iostream>

namespace demo1 {
struct A {
  A() {
    init();
  }
  A(int a) : A() {} // 委派构造
 private:
  void init() {
    std::cout << "init" << std::endl;
  }
};
}

namespace demo2 {
struct A {
  A() {
    init();
  }
  A(int a) : A() {}
  A(int a, char* s) : A(a) {} // A(int)既是目标构造函数也是委派构造函数, 注意不能形成环
 private:
  void init() {}
};
}
namespace demo3 {
struct A {
  A() {
    init();
  }
  // A(int a) : A(), a_(a) {} // 不能同时委派和使用初始化表
  A(int a) : A() {
    a_ = a;
  }
 private:
  void init() {}
  int a_;
};
}
namespace demo4 {
struct A {
  A() {
    std::cout << "A()" << std::endl;
    throw 0;
  }
A(int a) try :
    A() {
    std::cout << "A(int)" << std::endl;
  } catch (...) {
    std::cout << "catch exception!" << std::endl;
    // exit(1);
  }
};
}


int main() {

  demo4::A a(1);

  getchar();
  return 0;
}