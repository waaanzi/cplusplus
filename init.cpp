/*
快速初始化成员变量
C++11
非静态成员变量，可以在类声明中进行就地列表初始化（=或{}都可以），但初始化列表的效果优于就地初始化。
非常量静态数据成员，C++11与C++98保持一致，需要到头文件以外定义它。
*/

#include <iostream>
#include <string>

enum {
  apple,
};

class A1 {
 public:
  A1() : a9_(100) {}

  int a1_;
  const int a2_ = 1;
  static int a3_;
  // static int a3_ = 1;  // 编译不通过,需要类外初始化
  static const int a4_ = 1;
  // static const double a5_ = 2.0;  // 编译不通过,常量静态数据成员需要是整型或者枚举
  // static const std::string a5_ = "hey";
  static const int a6_ = apple;

  std::string a7_ = "hi";
  std::string a8_{ "hi" };

  int a9_{ 200 };
};

int A1::a3_ = 1;

int main() {

  A1 a;

  sizeof(a.a1_);
  std::cout << "a.a9_:  " << a.a9_;

  getchar();

  return 0;
}