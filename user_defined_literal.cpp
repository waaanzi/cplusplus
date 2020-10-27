/*
用户定义字面量
定义：通过定义用户定义的后缀，允许整数、浮点数、字符及字符串字面量产生用户定义类型的对象。
语法：
十进制字面量 ud-后缀  (1)
八进制字面量 ud-后缀  (2)
十六进制字面量 ud-后缀 (3)
二进制字面量 ud-后缀  (4)
分数常量 指数部分(可选) ud-后缀 (5)
数字序列 指数部分 ud-后缀 (6)
字符字面量 ud-后缀 (7)
字符串字面量 ud-后缀  (8)

用户定义的ud-后缀必须以_开头。

字面量运算符:用户定义字面量所调用的函数
形式：
operator "" 标识符
operator 用户定义字符串字面量 (C++14 起)

第二种形式：用户定义字符串字面量：字符序列 "" 后不带空格，后随将作为ud-后缀的字符序列。这种特殊语法使得将语言关键词和保留标识符用作 ud-后缀 成为可能。
例如允许下划线后随大写字母的用法（其他情况下这是保留标识符）
若字面量运算符是模板，则它必须有空形参列表，而且只能有一个模板形参，模板形参必须是元素类型为 char 的非类型模板形参包
（该情况下称之为数值字面量运算符模板）或类类型的非类型模板形参（该情况下称之为字符串字面量运算符模板, C++20起）

字面量运算符仅允许下列形参列表：（不允许默认实参，不允许C语言连接）

( const char * )  (1)
( unsigned long long int )  (2)
( long double ) (3)
( char )  (4)
( wchar_t ) (5)
( char8_t ) (6) (C++20 起)
( char16_t )  (7)
( char32_t )  (8)
( const char * , std::size_t )  (9)
( const wchar_t * , std::size_t ) (10)
( const char8_t * , std::size_t ) (11)  (C++20 起)
( const char16_t * , std::size_t )  (12)
( const char32_t * , std::size_t )  (13)

对于用户定义整数字面量
若字面量运算符有重载，优先形参类型 unsigned long long 的字面量运算符，即调用operator "" X(nULL)
否则调用原始字面量运算符或数值字面量运算符模板
operator "" X("n")
operator "" X<'c1', 'c2', 'c3'..., 'ck'>()
对于用户定义浮点字面量
若字面量运算符有重载，优先形参类型 long double 的字面量运算符，即调用operator "" X(nULL)
否则调用原始字面量运算符或数值字面量运算符模板

对于用户定义字符串字面量
a) 若重载集包含带非类型模板形参的字符串字面量运算符模板，且 str 对它是良构的模板实参，则用户定义字面量表达式被当作函数调用 operator "" X<str>()，
(C++20 起)
b) 否则，用户定义字面量表达式被当做函数调用 operator "" X (str, len)，其中 len 是字符串字面量的长度，不包含终止空字符

对于用户定义字符字面量
调用 operator "" X (ch)

注意
*/
#include <iostream>
#include <string>

namespace demo1 {
void operator "" _a(const char* s) {
  std::cout << "operator \"\"_a(const char* s)  " << s << std::endl;
}
}

namespace demo2 {
template <char... args>
void operator "" _a() {
  std::cout << "template  " << sizeof...(args) << std::endl;
}
}

namespace demo3 {
void operator "" _a(const char* s) {
  std::cout << "operator \"\"_a(const char* s)" << std::endl;
}

void operator ""_a(unsigned long long i) {
  std::cout << "operator \"\"_a(unsigned long long i)" << std::endl;
}
}

namespace demo4 {
void operator "" _a(const char* s) {
  std::cout << "operator \"\"_a(const char* s)" << std::endl;
}

void operator ""_a(long double f) {
  std::cout << "operator \"\"_a(long double f)" << std::endl;
}
}

namespace demo5 {
void operator "" _a(const char* s) {
  std::cout << "operator \"\"_a(const char* s)" << std::endl;
}

void operator "" _a(const char* s, size_t) {
  std::cout << "operator \"\"_a(const char* s, size_t)" << std::endl;
}

void operator "" _a(const char16_t* s, size_t) {
  std::cout << "operator \"\"_a(const char16_t* s, size_t)" << std::endl;
}

void operator "" _a(const char32_t* s, size_t) {
  std::cout << "operator \"\"_a(const char32_t* s, size_t)" << std::endl;
}
}

namespace demo6 {
void operator ""  _A(const char32_t* s, size_t) {}
void operator ""_A(const char* s) {
  std::cout << "operator \"\"_A(const char* s)" << std::endl;
}
}

int main() {
  {
    using namespace demo1;
    123_a;
  }

  {
    using namespace demo2;
    123_a;
  }

  {
    using namespace demo3;
    123_a;
  }

  {
    using namespace demo4;
    123_a;
    1.2_a;
  }
  {
    using namespace demo5;
    u8"123"_a;
    u"123"_a;
  }

  {
    using namespace demo6;
    123_A;
  }

  std::cin.get();
  return 0;
}