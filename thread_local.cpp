
/*
thread_local

存储类指定符
auto - 自动存储期。(C++11 前) C++11 起， auto 不再是存储类指定符；它被用于指示类型推导。
register - 自动存储期。亦提示编译器将此对象置于处理器的寄存器。(C++17 前), C++17弃用
static - 静态或线程存储期和内部链接。
extern - 静态或线程存储期和外部链接。
thread_local - 线程存储期。(C++11 起)
关键词 mutable 在 C++ 文法中是存储类指定符，尽管它不影响存储期或链接。

存储期
程序中的所有对象拥有下列存储期之一：
自动存储期。对象的存储在外围代码块开始时分配，而在结束时解分配。除了声明为 static 、 extern 或 thread_local 的所有局部对象拥有此存储期。
静态存储期。对象的存储在程序开始时分配，而在程序结束时解分配。只存在对象的一个实例。
  所有声明于命名空间作用域（包含全局命名空间）的对象，加上声明带有 static 或 extern 的对象拥有此存储期。
线程存储期。对象的存储在线程开始时分配，而在线程结束时解分配。
  每个线程拥有其自身的对象实例。唯有声明为 thread_local 的对象拥有此存储期。 thread_local 能与 static 或 extern 一同出现，以调整链接。(C++11 起)
动态存储期。通过使用动态内存分配函数，由请求分配和解分配对象的存储。

链接
指代对象、引用、函数、类型、模板、命名空间或值的名称可拥有链接。若名称拥有链接，则其所指代的实体与另一作用域中的声明所引入的同一名称所指代者相同。
若变量、函数或另一实体声明于数个作用域，但无充分的链接，则生成实体的数个实例。辨认下列链接：
无链接。名称只能从其所在的作用域使用。
任何声明于块作用域的下列名称无链接：
  不显式声明为 extern 的变量（无关乎 static 修饰符）；
  局部类与其成员函数；
  其他声明于块作用域的名称，例如 typedef 、枚举及枚举项。
内部链接。名称可从当前翻译单元中的所有作用域使用。
  任何声明于命名空间作用域的下列名称拥有内部链接；
  声明为 static 的变量、函数或函数模板；
  不是 extern 的，且先前未声明拥有外部链接的，非 volatile 非 inline (C++17 起) const 限定变量（包含 constexpr ）；
  匿名联合体的数据成员。
  另外，所有声明于无名命名空间或无名命名空间内的名称，即使是显式声明为 extern 者，均拥有内部链接。(C++11 起)
外部链接。名称能从其他翻译单元中的作用域使用。拥有外部链接的变量和函数亦拥有语言链接，这使得可以链接到以不同编程语言书写的翻译单元。
任何声明于命名空间作用域的下列名称拥有外部链接，除非命名空间无名或为无名命名空间所含有 (C++11 起)；
  未列于上的变量与函数（即不声明为 static 的函数、不声明为 static 的命名空间作用域非 const 变量，和所有声明为 extern 的变量）；
  枚举；
  类名、其成员函数、静态数据成员（不论是否 const ）、嵌套类及枚举，及首次以类体内的 friend 声明引入的函数；
  所有未列于上的模板名（即不声明为 static 的函数模板）。
任何首次声明于块作用域的下列名称拥有外部链接：
  声明为 extern 的变量名；
  函数名。

注意：
位于顶层命名空间作用域（ C 中的文件作用域），且是 const 而非 extern 在 C 中拥有外部链接，但在 C++ 中拥有内部链接。
从不同作用域指涉的，带内部或外部链接的 thread_local 变量名称，可能指代相同或不同实例，依赖于代码执行于相同还是不同的线程。
extern 关键词亦可用于指定语言链接和显式模板实例化声明，但在这些情况中不是存储类指定符。

*/


#include <iostream>
#include <mutex>
#include <string>
#include <thread>

thread_local unsigned int rage = 1;
std::mutex cout_mutex;

void increase_rage(const std::string& thread_name) {
  ++rage; // 在锁外修改 OK ；这是线程局域变量
  std::lock_guard<std::mutex> lock(cout_mutex);
  std::cout << "Rage counter for " << thread_name << ": " << rage << '\n';
}

void test() {
  thread_local int i = 0;
  printf("id=%d, n=%d\n", std::this_thread::get_id(), i);
  i++;
}

void test2() {
  test();
  test();
}

int main() {
  std::thread a(increase_rage, "a"), b(increase_rage, "b");

  {
    std::lock_guard<std::mutex> lock(cout_mutex);
    std::cout << "Rage counter for main: " << rage << '\n';
  }

  a.join();
  b.join();

  std::thread t1(test);
  std::thread t2(test);
  t1.join();
  t2.join();

  std::thread t3(test2);
  t3.join();

  system("pause");
  return 0;
}