/*
<type_traits>
检查类型是否为简旧数据（POD）类型
template< class T >
struct is_pod; (C++11 起)(C++20 中弃用)

POD类型（Plain Old Data）简旧数据类型
POD类型与用于C程序语言的类型兼容，即能直接以其二进制形式与C库交互。C++20弃用。

C++11标准中，满足POD的类类型要求：
平凡类型（trivial type）
标准布局类型（standard layout type）
没有非POD的非静态成员


检查类型是否平凡
template< class T >
struct is_trivial;(C++11 起)

平凡类型的要求：
可平凡复制 (TriviallyCopyable)
拥有一个或多个默认构造函数，全部均为平凡或被删除，至少有一个未被删除。

可平凡复制
要求
每个复制构造函数为平凡或被删除
每个移动构造函数为平凡或被删除
每个复制赋值运算符为平凡或被删除
每个移动赋值运算符平凡或被删除
至少一个复制构造函数、移动构造函数、复制赋值运算符或移动赋值运算符未被删除
平凡而未被删除的析构函数


这隐含该类无虚函数或虚基类。
标量类型和可平凡复制 (TriviallyCopyable) 对象的数组，还有这些类型的 const 限定（但非 volatile 限定）版本，也是可平凡复制 (TriviallyCopyable) 的。

**********************************************


检查是否是一个标准布局类型
template< class T >
struct is_standard_layout;(C++11 起)


全部非静态数据成员必须拥有同一访问控制
无虚函数或虚基类
无引用类型的非静态数据成员
所有非静态数据成员和基类自身是标准布局类型

满足以下之一
无带非静态数据成员的基类，或在最后导出类无非静态数据成员，且至多有一个基类拥有非静态数据成员
无与首个非静态数据成员同类型的基类（见空基类优化）
(C++14 前)

(C++14 起)
无二个拥有相同类型的（可能间接的）基类子对象
struct Q {};
struct S : Q { };
struct T : Q { };
struct U : S, T { }; // 非标准布局类：二个 Q 类型的基类子对象
在同一类中声明所有非静态数据成员和位域（要么全在导出类，要么在某个基类）
struct B { int i; };         // 标准布局类
struct C : B { };            // 标准布局类
struct D : C { };            // 标准布局类
struct E : D { char : 4; };  // 非标准布局类

无拥有与如下者相同类型的基类子对象
对于非联合类型，为首个非静态数据成员（见空基类优化），若该数据成员拥有非联合类类型，则为其首个数据成员，或者若该数据成员为联合体类型，则为其所有非静态数据成员，或者若该数据成员为数组类型，则为其元素类型，依此递归。
对于联合体类型，为任何非静态数据成员，若该数据成员拥有非联合类类型，则为其首个数据成员，或者若该数据成员为联合体类型，则为其所有非静态数据成员，或者若该数据成员为数组类型，则为其元素类型，依此递归。
对于数组类型，为数组元素的类型，若该数据成员拥有非联合类类型，则为其首个数据成员，或者若该数据成员为联合体类型，则为其所有非静态数据成员，或者若该数据成员为数组类型，则为其元素类型，依此递归。





将POD划分为两个基本概念的合集 平凡的（trivial）和标准布局的（standard layout）
平凡的（平凡构造、析构、拷贝构造，赋值、移动构造、赋值、不能包含虚函数以及虚基类）
判断平凡的模板类  template <typename T>  struct std::is_trivial        <type_traits>
标准布局
（所有非静态成员有相同的访问权限、
【派生类中有非静态成员，且只有一个仅包含静态成员的基类 || 基类有非静态成员，而派生类没有非静态成员】、
类中第一个非静态成员的类型与其基类不同、没有虚函数和虚基类、所有非静态数据成员均符合标准布局类型，其基类也符合标准布局）
判断标准布局的模板类   template <typename T>  struct std::is_standard_layout    <type_traits>
判断POD的模板类    template <typename T>  struct std::is_pod     <type_traits>
POD好处：字节赋值（memcpy memset）、提供对c内存布局兼容、保证静态初始化的安全有效。
*/

#include <string>
#include <iostream>

struct data {
  int a;
  int b;
  std::string s;
};

int main() {
  data d1;
  d1.a = 9;
  d1.b = 99;
  d1.s = "hello";

  data d2 = d1;

  std::cout << d2.a << d2.b << d2.s << std::endl;

  getchar();
  return 0;
}