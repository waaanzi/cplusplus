#include <iostream>

#include <utility>
#include <vector>

#include <memory>

/*
https://zh.cppreference.com/w/cpp/language/noexcept_spec
noexcept 指定符
指定函数是否抛出异常。
两种语法：
noexcept	(1) 同noexcept(true)
noexcept(expression)	(2)
C++17起：noexcept 规定是函数类型的一部分，并可以作为函数声明器的一部分出现。
C++17前：
noexcept 规定不是函数类型的一部分（正如同动态异常规定），而且只能在声明函数、变量、函数类型的非静态数据成员、指向函数指针、
到函数的引用或指向成员函数的指针时，和声明类型正好是指向函数指针或到函数的引用的参数或返回类型时，作为 lambda 声明器或顶层函数声明器的一部分出现。
它不能出现于 typedef 或类型别名声明。
void f() noexcept; // 函数 f() 不抛出
void (*fp)() noexcept(false); // fp 指向可能抛出的函数
void g(void pfa() noexcept);  // g 接收指向不抛出的函数的指针
// typedef int (*pf)() noexcept; // 错误

动态异常规定：列出函数可能直接或间接抛出的异常
在C++11中弃用

*/

/*
https://zh.cppreference.com/w/cpp/language/noexcept
noexcept 运算符
noexcept运算符进行编译时检查，若表达式声明为不抛出任何异常则返回true
语法：
noexcept( expression ) 
返回bool类型的纯右值
注意：noexcept 运算符不对 expression 求值。
C++17起：若 expression 的潜在异常集合为空则结果为true，否则为false。
潜在异常集合的概念比较复杂，以修改的cppreference上的示例进行说明。
C++17前：
若 expression 含有至少一个下列潜在求值的构造则结果为 false：
  调用无不抛出异常指定的任意类型函数，除非它是常量表达式。
  throw 表达式。
  目标类型是引用类型，且转换需要运行时检查时的dynamic_cast表达式
  参数类型是多态类类型的 typeid 表达式
所有其他情况下结果是true。

*/

/*
用于函数模板，以声明函数将对某些类型抛出异常，但不对其他类型抛出。
template <class T>
void fun() noexcept(noexcept(T())){}
*/

// noexcept 运算符 
void may_throw() {};
void no_throw() noexcept {};
auto lmay_throw = [] {};
auto lno_throw = []() noexcept {};

class T {
};
class T1 {
public:
  ~T1() {}
};
class T2 {
public:
  ~T2() {}
  int v;
};
class T3 {
public:
  ~T3() {}
  std::vector<int> v;
};
class T4 {
public:
  std::vector<int> v;
};

int main()
{
  T t;
  T1 t1;
  T2 t2;
  T3 t3;
  T4 t4;

  std::vector<int> vc;

  std::cout << std::boolalpha
    << "Is may_throw() noexcept? " << noexcept(may_throw()) << '\n'
    << "Is no_throw() noexcept? " << noexcept(no_throw()) << '\n'
    << "Is lmay_throw() noexcept? " << noexcept(lmay_throw()) << '\n'
    << "Is lno_throw() noexcept? " << noexcept(lno_throw()) << '\n'
    << "Is ~T1() noexcept? " << noexcept(std::declval<T1>().~T1()) << '\n'

    << '\n'
    << '\n'

    << "Is T(rvalue T) noexcept? " << noexcept(T(std::declval<T>())) << '\n'
    << "Is T(lvalue T) noexcept? " << noexcept(T(t)) << '\n'
    << '\n'

    << "Is T1(rvalue T1) noexcept? " << noexcept(T1(std::declval<T1>())) << '\n'
    << "Is T1(lvalue T1) noexcept? " << noexcept(T1(t1)) << '\n'
    << '\n'

    << "Is T2(rvalue T2) noexcept? " << noexcept(T2(std::declval<T2>())) << '\n'
    << "Is T2(lvalue T2) noexcept? " << noexcept(T2(t2)) << '\n'
    << '\n'

    << "Is T3(rvalue T3) noexcept? " << noexcept(T3(std::declval<T3>())) << '\n'
    << "Is T3(lvalue T3) noexcept? " << noexcept(T3(t3)) << '\n'
    << '\n'

    << "Is T4(rvalue T4) noexcept? " << noexcept(T4(std::declval<T4>())) << '\n'
    << "Is T4(lvalue T4) noexcept? " << noexcept(T4(t4)) << '\n'
    << '\n'

    << "Is std::vector<int>(rvalue std::vector<int>) noexcept? " << noexcept(std::vector<int>(std::declval<std::vector<int>>())) << '\n'
    << "Is std::vector<int>(lvalue std::vector<int>) noexcept? " << noexcept(std::vector<int>(vc)) << '\n';

  system("pause");
}