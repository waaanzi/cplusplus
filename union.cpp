/*
C++98对联合体Union有一些限制：所有成员必须是POD类型的；不允许拥有静态或引用类型的成员；
C++11：任何非引用类型都可以成为联合体的数据成员，也就是非受限联合体（Unrestricted Union）。可以有静态成员函数，但是不允许静态数据成员。
C++11会默认删除一些非受限联合体的默认函数。

在C++11标准中，当联合体中有一个非POD的成员，并且该非POD成员有非平凡的构造函数，那么这个联合体的默认构造函数就会被编译器删除，同理，其他的特殊成员函数比如默认拷贝构造函数，拷贝赋值构造函数及析构函数，也遵循这个标准。
*/

#include <iostream>
#include <type_traits>

namespace demo1 {
class A {
  A(int a) {}
};

// C++11 通过， C++98不通过
union u {
  A a;
  int i;

public:
  u() {};
};
}

namespace demo2 {
class A {
  static void func();
};

void A::func() {
}

// C++11 通过， C++98通过
union u {
  A a;
  int i;
};
}

namespace demo3 {
class A {
 public:
  static int a_;
};

int A::a_ = 1;

// C++11 通过， C++98通过
union u {
  A a;
  int i;
};
}

int main() {
  {
    using namespace demo1;
    std::cout << "is_pod" << std::is_pod<demo1::A>::value << std::endl;
    std::cout << "is_trivial" << std::is_trivial<demo1::A>::value << std::endl;
    std::cout << "is_standard_layout" << std::is_standard_layout<demo1::A>::value << std::endl;
    u t;
  }
  {
    using namespace demo2;
    u t;
  }
  {
    using namespace demo3;
    u t;
    std::cout << t.a.a_;
  }

  std:: cin.get();
  return 0;
}