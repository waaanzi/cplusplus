
/*
*  c++11 std::shared_ptr demo
*/

// https://zh.cppreference.com/w/cpp/memory/shared_ptr

/*
template< class T > class shared_ptr; (C++11 起)
std::shared_ptr 是通过指针保持对象共享所有权的智能指针，多个shared_ptr可占有同一对象。对被管理的资源进行引用计数。

shared_ptr 能在存储指向一个对象的指针时共享另一对象的所有权。此特性能用于在占有其所属对象时，指向成员对象。
存储的指针通过get() 、解引用及比较运算符访问。被管理指针在 use_count等于零时传递给删除器。

shared_ptr可以不占用对象，即为空。

常用方法
release 返回一个指向被管理对象的指针，并释放所有权
reset 替换被管理对象
swap 交换被管理对象

get 返回指向被管理对象的指针
use_count 返回shared_ptr所指对象的引用计数
operator bool 检查是否有关联的被管理对象

非成员函数
make_shared
重载的关系运算符
std::swap<std::shared_ptr>
allocate_shared 创建共享指针，管理用分配器分配的新对象

辅助类
std::hash<std::shared_ptr>  (C++11)
std::shared_ptr 的哈希支持(类模板特化)
std::atomic<std::shared_ptr>  (C++20)
原子共享指针(类模板特化)

注意
1 只能通过复制构造或复制赋值其值给另一shared_ptr，将对象所有权与另一shared_ptr共享。
用另一shared_ptr所占有的底层指针创建新的shared_ptr导致未定义行为。
2 使用shared_ptr包装this指针
    使用enable_shared_from_this
    shared_from_this
3 shared_ptr循环引用导致内存泄露
4 多线程中使用shared_ptr
    其中一种方式是使用weak_ptr,3也可以用它解决

weak_ptr
std::weak_ptr是一种智能指针，它对被std::shared_ptr管理的对象攒在非拥有性（“弱”）引用。在访问所引用的修啊ing钱必须先转换为std::shared_ptr
std::weak_ptr可以用来避免std::shared_Ptr的循环引用

常用函数：
reset 释放被管理对象的所有权
swap 交换被管理对象
use_count 返回管理该对象的shared_ptr对象数量
expired 检查被引用的对象是否已删除
lock 创建管理被引用的对象的shared_ptr
owner_before 提供弱指针的基于拥有者顺序

#include <iostream>
#include <memory>

std::weak_ptr<int> gw;

void f()
{
if (auto spt = gw.lock()) { // 使用之前必须复制到 shared_ptr
std::cout << *spt << "\n";
}
else {
std::cout << "gw is expired\n";
}
}

int main()
{
{
auto sp = std::make_shared<int>(42);
gw = sp;

f();
}

f();
}



*/

#include <iostream>
#include <memory> // std::shared_ptr
#include <thread>
#include <chrono>
#include <mutex>

struct Base
{
  Base() { std::cout << "  Base::Base()\n"; }
  // 注意：此处非虚析构函数 OK
  ~Base() { std::cout << "  Base::~Base()\n"; }
};

struct Derived : public Base
{
  Derived() { std::cout << "  Derived::Derived()\n"; }
  ~Derived() { std::cout << "  Derived::~Derived()\n"; }
};

void thr(std::shared_ptr<Base> p)
{
  std::this_thread::sleep_for(std::chrono::seconds(1));
  std::shared_ptr<Base> lp = p; // 线程安全，虽然自增共享的 use_count
  {
    static std::mutex io_mutex;
    std::lock_guard<std::mutex> lk(io_mutex);
    std::cout << "local pointer in a thread:\n"
      << "  lp.get() = " << lp.get()
      << ", lp.use_count() = " << lp.use_count() << '\n';
  }
}

int main()
{
  std::shared_ptr<Base> p; 

  if (p)
  {
    std::cout << "has p" << '\n';
  }
  else
  {
    std::cout << " not has p" << '\n';
  }

  p = std::make_shared<Derived>();
  if (p)
  {
    std::cout << " 1 has p" << '\n';
  }
  else
  {
      std::cout << " 1 not has p" << '\n';
  }

  std::shared_ptr<Base> p1 = std::make_shared<Base>();
  p1.reset();
  std::shared_ptr<Base> p2 = std::make_shared<Derived>();
  p2.reset();
  std::shared_ptr<Base> p3(new Base());
  auto p4(p3);
  auto p5 = p3;
  auto p6 = nullptr;

  std::cout << "Created a shared Derived (as a pointer to Base)\n"
    << "  p.get() = " << p.get()
    << ", p.use_count() = " << p.use_count() << '\n';
  std::thread t1(thr, p), t2(thr, p), t3(thr, p);
  p.reset(); // 从 main 释放所有权
  std::cout << "Shared ownership between 3 threads and released\n"
    << "ownership from main:\n"
    << "  p.get() = " << p.get()
    << ", p.use_count() = " << p.use_count() << '\n';
  t1.join(); t2.join(); t3.join();
  std::cout << "All threads completed, the last one deleted Derived\n";

  system("pause");
}
