#include <iostream>
#include <memory>

/*
std::enable_shared_from_this
template< class T > class enable_shared_from_this;(C++11 起)
std::enable_shared_from_this 能让其一个对象（假设其名为 t ，且已被一个 std::shared_ptr 对象 pt 管理）
安全地生成其他额外的 std::shared_ptr 实例（假设名为 pt1, pt2, ... ） ，它们与 pt 共享对象 t 的所有权。
一个使用场景是异常调用中的保活。
成员函数
shared_from_this 返回共享 *this 所有权的 shared_ptr
weak_from_this  (C++17) 返回共享 *this 所有权的 weak_ptr
*/

class A {
 public:
  A() {
    std::cout << "A()" << std::endl;
  }
  ~A() {
    std::cout << "~A()" << std::endl;
  }

  std::shared_ptr<A> ptr_dangerous() {
    return std::shared_ptr<A>(this);
  }
};

class B : public std::enable_shared_from_this<B> {
 public:
  B() {
    std::cout << "B()" << std::endl;
  }
  ~B() {
    std::cout << "~B()" << std::endl;
  }

  std::shared_ptr<B> ptr() {
    return shared_from_this();
  }
};
int main() {
  {
    std::cout << 1 << std::endl;
    auto p = std::make_shared<B>();
    auto p1 = p->ptr();
    std::cout << "use_count(): " << p.use_count() << std::endl;
  }

  {
    std::cout << 2 << std::endl;
    auto p = std::make_shared<A>();
    auto p1 = p->ptr_dangerous();
    std::cout << "use_count(): " << p.use_count() << std::endl;
  }

  system("pause");
  return 0;
}