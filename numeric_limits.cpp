/*

头文件 <limits>
template <class T> numeric_limits;

Provides information about the properties of arithmetic types (either integral or floating-point)
in the specific platform for which the library compiles.
提供算术类型（整型或者浮点型）的属性信息。

This class template is specialized for every fundamental arithmetic type, with its members describing the properties of type T.
This template shall not be specialized for any other type.
该类模板提供了每个基本算术类型的特化，类成员描述类型的属性；而其他类型并没有进行特化，将使用默认的模板定义。

成员和成员函数均为静态

C++11
This template is also specialized for all const and/or volatile qualifications of these types,
with the same values as their unqualified specializations.
类模板也提供了带有cv限定符的类型的特化版本，它的值与不带限定符的特化一样。

*/

#include <limits>
#include <iostream>

int main() {
  std::cout << "type\tlowest()\tmin()\t\tmax()\n\n";

  std::cout << "uchar\t"
            << +std::numeric_limits<unsigned char>::lowest() << '\t' << '\t'
            << +std::numeric_limits<unsigned char>::min() << '\t' << '\t'
            << +std::numeric_limits<unsigned char>::max() << '\n';
  std::cout << "int\t"
            << std::numeric_limits<int>::lowest() << '\t'
            << std::numeric_limits<int>::min() << '\t'
            << std::numeric_limits<int>::max() << '\n';
  std::cout << "float\t"
            << std::numeric_limits<float>::lowest() << '\t'
            << std::numeric_limits<float>::min() << '\t'
            << std::numeric_limits<float>::max() << '\n';
  std::cout << "double\t"
            << std::numeric_limits<double>::lowest() << '\t'
            << std::numeric_limits<double>::min() << '\t'
            << std::numeric_limits<double>::max() << '\n';

  getchar();
}
