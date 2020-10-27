/*
局部和匿名类型作模板实参
将C++98中的该限制放开
但不能在模板实参的位置进行以上的类型的声明定义
*/

template <typename T>
class Demo {};

template <typename T>
void func(T t) {}

struct S1 {
} a1;

struct {} a2;  // 匿名类型变量

typedef struct {}  S2; // 匿名类型？

int main() {

  struct S3 {} a3; // 局部类型

  Demo<S1> d1; // C++98 通过 C++11通过
  Demo<S2> d2; // C++98 通过 C++11通过！！
  Demo<S3> d3; // C++98 错误 C++11通过
  // Demo < struct {} > d4;

  func(a1); // C++98 通过 C++11通过
  func(a2); // C++98 错误 C++11通过
  func(a3); // C++98 错误 C++11通过

  return 0;
}