/*
模板函数的默认模板参数

C++98中，引入了函数模板和类模板，允许模板类声明的时候有默认模板参数，但是不支持函数模板。
C++11 开始支持，区别是模板函数的默认模板参数不需要“从右往左”依次指定。特别，模板参数的默认形参不是模板参数推导的依据。
*/

#include <iostream>

// template <typename T1 = int, typename T2> // error
// class A1 {};

template <typename T1, typename T2 = int>
class A2 {};

template <typename T1 = int, typename T2>
void f1() {
  std::cout << "f1" << std::endl;
};

template <typename T1, typename T2 = int>
void f2() {
  std::cout << "f2" << std::endl;
};

int main() {
  // f1<int>(); //error
  f1<int, int>();
  f2<int>();
  getchar();
  return 0;
}