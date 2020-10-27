#include <iostream>
#include <string>

#include <memory>

/*
*  c++ std::allocator demo
*/
using std::cout;

int a = 1;

void f()
{
  int a = 1;
}

int main()
{
  // 两个主要函数：allocate和deallocate
  std::allocator<int> a;
  int * p = a.allocate(20);
  a.deallocate(p, 20);

  // consturct destory在C++17中弃用，C++20中移除
  system("pause");
}