#include <iostream>
#include <memory> // std::unique_ptr

#include <fstream>
#include <vector>
#include <functional>
#include <cstdio> 
#include <cassert> // assert

/*
*  c++11 std::unique_ptr demo
*/

using std::cin;

  // https://zh.cppreference.com/w/cpp/memory/unique_ptr

/*
template<class T, class Deleter = std::default_delete<T>> class unique_ptr; (1)	(C++11 起)
template <class T, class Deleter> class unique_ptr<T[], Deleter>; (2)	(C++11 起)

两个版本，单对象版本和对象数组版本
单对象版本重载了*和->运算符，对象数组版本重载了[]运算符

参数要求
Deleter must be FunctionObject or lvalue reference to a FunctionObject or lvalue reference to function, 
callable with an argument of type unique_ptr<T, Deleter>::pointer
Deleter必须是函数对象，或者函数对象的左值引用或者函数的右值引用，可以unique_ptr<T, Deleter>类型的参数调用

unique_ptr独占对象，只有移动语义（没有拷贝语义）
unique_ptr可以不占用对象，即为空
标准库早期版本中定了auto_ptr，它具有unique_ptr的部分特征，但不是全部，例如不能在容器中保存auto_ptr,不能从函数中返回auto_ptr等等，这也是unique_ptr
主要的使用场景

应用场景
1 为动态申请的资源提供异常安全保证
2 返回函数内动态申请资源的所有权
3 在容器中保存指针
4 管理动态数组
5 作为auto_ptr的替代品

常用方法
release 返回一个指向被管理对象的指针，并释放所有权
reset 替换被管理对象
swap 交换被管理对象

get 返回指向被管理对象的指针
get_deleter 返回用于析构被管理对象的删除器
operator bool 检查是否有关联的被管理对象

非成员函数
make_unique C++14
重载的关系运算符
std::swap<std::unique_ptr>
*/

struct B {
  virtual void bar() { std::cout << "B::bar\n"; }
  virtual ~B() = default;
};
struct D : B
{
  D() { std::cout << "D::D\n"; }
  ~D() { std::cout << "D::~D\n"; }
  void bar() override { std::cout << "D::bar\n"; }
};

// 消费 unique_ptr 的函数能以值或以右值引用接收它
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
  p->bar();
  return p;
}

void close_file(std::FILE* fp) { std::fclose(fp); }

int main()
{
  std::cout << "unique ownership semantics demo\n";
  {
    auto p = std::make_unique<D>(); // p 是占有 D 的 unique_ptr
    auto q = pass_through(std::move(p));
    assert(!p); // 现在 p 不占有任何内容并保有空指针
    q->bar();   // 而 q 占有 D 对象
  } // ~D 调用于此

  std::cout << "Runtime polymorphism demo\n";
  {
    std::unique_ptr<B> p = std::make_unique<D>(); // p 是占有 D 的 unique_ptr
                                                  // 作为指向基类的指针
    p->bar(); // 多态

    std::vector<std::unique_ptr<B>> v;  // unique_ptr 能存储于容器
    v.push_back(std::make_unique<D>()); 
    v.push_back(std::move(p));
    v.emplace_back(new D);
    for (auto& p : v) p->bar(); // 多态
  } // ~D called 3 times

  std::cout << "Custom deleter demo\n";
  std::ofstream("demo.txt") << 'x'; // 准备要读的文件
  {
    std::unique_ptr<std::FILE, void(*)(std::FILE*) > fp(std::fopen("demo.txt", "r"),
      close_file);
    if (fp) // fopen 可以打开失败；该情况下 fp 保有空指针
      std::cout << (char)std::fgetc(fp.get()) << '\n';
  } // fclose() 调用于此，但仅若 FILE* 不是空指针
    // （即 fopen 成功）

  std::cout << "Custom lambda-expression deleter demo\n";
  {
    std::unique_ptr<D, std::function<void(D*)>> p(new D, [](D* ptr)
    {
      std::cout << "destroying from a custom deleter...\n";
      delete ptr;
    });  // p 占有 D
    p->bar();
  } // 调用上述 lambda 并销毁 D

  std::cout << "Array form of unique_ptr demo\n";
  {
    std::unique_ptr<D[]> p{ new D[3] };
  } // 调用 ~D 3 次


  std::cout << "demo1\n";
  {
    std::unique_ptr<D[]> p{ new D[3] };
    p.reset();
    assert(!p);
  }
  std::cout << "demo2\n";
  {
    std::unique_ptr<D[]> p{ new D[3] };
    p = nullptr;
    assert(!p);
  }
  system("pause");
}
