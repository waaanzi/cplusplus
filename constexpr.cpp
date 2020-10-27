#include <iostream>

/*
https://zh.cppreference.com/w/cpp/language/constexpr

constexpr
常量表达式（const expression）是指值不会改变并且在编译过程中就得到计算结果的表达式。
这种表达式能用作非类型模板实参、数组大小、并用于其他要求常量表达式的语境。

C++11用constexpr申明来由编译器检验变量的值是否为一个常量表达式
C++14前 用于对象或非静态成员函数申明的constexpr指定符蕴含const
C++17起 用于函数声明的constexpr指定符或static成员变量蕴含inline.
若函数或者函数模板的任何声明拥有constexpr,则每个声明必须都含有该指定符。

1 constexpr变量要求：
其类型必须是字面类型
必须被立即初始化
其初始化的完整表达式，包括所有隐式转换、构造函数调用等，都必须是常量表达式。

2 constexpr 函数要求：
它必须非虚(C++20 前)
其返回类型必须是字面类型 (LiteralType)
其每个参数都必须是字面类型 (LiteralType)
至少存在一组参数值，使得函数的一个调用能为被求值的核心常量表达式的子表达式（对于构造函数为足以用于常量初始化器） (C++14 起)。不要求对这点的诊断。
函数体必须是被删除或被默认化，或只含有下列内容：(C++14 前)
  空语句（平凡分号）
  static_assert 声明
  不定义类或枚举的 typedef 声明及别名声明
  using 声明
  using 指令
  恰好一条 return 语句。
函数体必须不含：(C++14 起)
  asm 声明
  goto 语句
  拥有异于 case 和 default 标号的语句
  try 块(C++20 前)
  非字面类型的变量定义
  静态或线程存储期变量的定义
  不进行初始化的变量定义。
  （ =default; 或 =delete; 的函数体不含任何上述内容。）

3 constexpr构造函数必须满足下列要求：
其每个参数都必须是字面类型
该类必须无虚基类
该构造函数必须无函数try块(C++20 前)
构造函数体必须被删除或被默认化或只含有下列内容：  (C++14 前)
  空语句
  static_assert 声明
  不定义类或枚举的 typedef 声明及别名声明
  using 声明
  using 指令
构造函数体必须满足 constexpr 函数体的制约(C++14 起)

对于 class 或 struct 的构造函数，每个子对象和每个非变体非 static 数据成员必须被初始化。若类是类联合体类，对于其每个非空匿名联合体成员，必须恰好有一个变体成员被初始化
对于非空 union 的构造函数，恰好有一个非 static 数据成员被初始化
每个被选作初始化非 static 成员和基类的构造函数必须是 constexpr 构造函数。

*/
int value() {
  return 20;
}

constexpr int value1(int i) {
  // int n = 1; c++11中不支持
  return i + 1;
}

class Point {
 public:
  constexpr Point(double xval = 0, double yval = 0) : x(xval), y(yval) { }
  constexpr double getX() const {
    return x;
  }
  constexpr double getY() const {
    return y;
  }
 private:
  double x, y;
};

int main() {
  {
    // vs2015不支持c99 的variable length array特性
    // int i = 5;
    // int arr[i]; err
  }

  // 运行时常量性 const
  {
    const int i = 1;
    const int* p = new int;
    const int n = value();
  }
  {
    // 数组长度
    const int i = 1;
    int vc[i];
    {
      const int n = value();
      // const vc[n]; error
    }
  }

  // 编译时常量性 constexpr
  {
    constexpr int i = 1;
    const int n = value();
    // constexpr int i1 = n; error
  }
  {
    // constexpr指针变量
    //constexpr int* p = new int; error
    constexpr int* p1 = nullptr;
    constexpr int* p1 = 0;
  }
  {
    // constexpr修饰的函数，当传入参数是可以在编译期计算出来时，产生constexpr变量；
    // 当传入参数不可以在编译期计算出来时，产生运行期遍历（constexpr等于不存在）。
    int val;
    // constexpr int n = value1(val); error
    constexpr int n = value1(1);
    int n11 = value1(val);
  }
  {
    // 有时需要自定义类型也作为字面值常量，这时候就需需要用constexpr修饰构造函数
    constexpr auto  pt = Point(10, 20);
  }

  // constexpr 作用
  // 第一 为了效率。效率是C++的设计哲学之一，编译期可以确定的东西，便可以提醒编译期优化，也可能存放在read-only memory中.
  // 第二 constexpr变量便可以用在诸如上数组长度指定，还有包括模板参数，case标签等场合，会便于使用.

  system("pause");
  return 0;
}