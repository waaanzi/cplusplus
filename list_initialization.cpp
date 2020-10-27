/*
list_initialization 列表初始化
从花括号初始化器列表初始化对象
语法：
直接列表初始化
T object { arg1, arg2, ... }; (1)
T { arg1, arg2, ... } (2)
new T { arg1, arg2, ... } (3)
Class { T member { arg1, arg2, ... }; };  (4)
Class::Class() : member{arg1, arg2, ...} {... (5)
复制列表初始化
T object = {arg1, arg2, ...}; (6)
function( { arg1, arg2, ... } ) (7)
return { arg1, arg2, ... } ;  (8)
object[ { arg1, arg2, ... } ] (9)
object = { arg1, arg2, ... }  (10)
U( { arg1, arg2, ... } )  (11)
Class { T member = { arg1, arg2, ... }; };  (12)

窄化转换
列表初始化通过禁止下列转换，对隐式转换加以限制：
从浮点类型到整数类型的转换
从 long double 到 double 或 float 的转换，以及从 double 到 float 的转换，除非源是常量表达式且不发生溢出
从整数类型到浮点类型的转换，除非源是其值能完全存储于目标类型的常量表达式
从整数或无作用域枚举类型到不能表示原类型所有值的整数类型的转换，除非源是其值能完全存储于目标类型的常量表达式

C++14起
聚合体直接从同类型的单元素花括号初始化器列表进行复制/移动初始化，但非聚合体首先考虑 initializer_list 构造函数

聚合体类型：
数组类型
符合以下条件的类类型（典型的为 struct 或 union）
  无私有或受保护非静态数据成员
  无用户声明的构造函数 (C++11 前)
  无用户提供的构造函数（允许显式预置或弃置的构造函数）(C++11 起)(C++17 前)
  无用户提供、继承或 explicit 构造函数（允许显式预置或弃置的构造函数）(C++17 起)(C++20 前)
  无用户声明或继承的构造函数(C++20 起)
  无虚、私有或受保护基类(C++17 起)
  无虚成员函数
  无默认成员初始化器(C++11 起)(C++14 前)
*/

#include <iostream>

struct  Demo {
  int a_;
  int b_;
  Demo(std::initializer_list<int> list) {
    std::cout << "Demo(std::initializer_list<int> list)" << std::endl;
  }
};

struct  Demo1 {
  int a_;
  int b_;
  Demo1(int a, int b) {
    a_ = a;
    b_ = b;
    std::cout << "Demo1(int a, int b)" << std::endl;
  }
};

struct  Demo2 {
  int a_;
  int b_;
  Demo2(int a, int b) {
    a_ = a;
    b_ = b;
    std::cout << "Demo2(int a, int b)" << std::endl;
  }
  Demo2(std::initializer_list<int> list) {
    std::cout << "Demo2(std::initializer_list<int> list)" << std::endl;
  }
};

int main() {
  {
    // 窄化转换
    long double a = 1.1;
    // int b{ a };
    // std::cout << b << std::endl;
  }

  {
    // 非聚合体首先考虑 initializer_list 构造函数
    Demo d{ 1, 2 };
    Demo1 d1{ 1, 2 };
    Demo2 d2{ 1, 2 };
  }

  std::cin.get();
  return 0;
}