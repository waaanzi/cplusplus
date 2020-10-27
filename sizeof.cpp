/*
C++11中支持对非静态成员的sizeof
*/

#include <iostream>

struct Demo {
  static int a;
  int b;
};

int main() {

  std::cout << "Demo::a: " << sizeof(Demo::a) << std::endl;
  std::cout << "Demo::b: " << sizeof(Demo::b) << std::endl;

  getchar();
  return 0;
}