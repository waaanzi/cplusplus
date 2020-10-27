/*
继承构造函数

C++ 11中对C++98的using申明的扩展
注意：
多继承中可能出现的冲突问题；
不适合基类构造函数是私有或者虚继承场景；
使用了继承构造函数，编译器不会再生成默认构造函数；
*/

#include <iostream>

// 一般写法
namespace demo1 {
struct A {
  A(int a) : a_(a) {}
  A(int a, const char* s) {}
  int a_;
};

struct B : A {
  B(int a, int b) : A(a), b_(b) {}
  B(int a, const char* s, int b) : A(a, s), b_(b) {}
  int b_;
};
// 若父类有较多版本的构造函数，该写法比较麻烦
}

// C++11 using申明的扩展使用
namespace demo2 {
struct A {
  A(int a) : a_(a) {}
  A(int a, const char* s) {}
  int a_;
};

struct B : A {
  using A::A; // 是隐式声明，不使用不产生真正函数代码，比透传节省空间
  int b_;
};
// B将继承A所有构造函数
}

// 特例， 父类构造函数有默认参数的情况
namespace demo3 {
struct A {
  A(int a = 100) : a_(a) {
    std::cout << "demo3 A constructor " << a_ << std::endl;
  }
  A(int a, const char* s) {
    std::cout << "demo3 A constructor int , const char* : " << a << s << std::endl;
  }
  int a_;
};

struct B : A {
  using A::A;
  int b_;
};
}

// 问题1 子类新增的成员如何初始化
// 就地初始化
// 问题2 多继承可能导致的继承构造函数冲突问题
namespace demo4 {
struct A {
  A() {}
  A(int a) : a_(a) {}
  int a_;
};

struct B {
  B() {}
  B(int b) : b_(b) {}
  int b_;
};

struct C : A, B {
  using A::A;
  using B::B;
  C(int c) {} // 显式定义冲突的继承构造函数
};
}

int main() {
  {
    demo3::B b;
    demo3::B b1(10);
    demo3::B b2(50, "hello");
  }

  getchar();
  return 0;
}

