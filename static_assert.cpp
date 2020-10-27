/*
在C++中，<cassert>或<cassert.h>中提供了assert宏（运行期断言）。可以定义NDEBUG来禁用assert宏。
C++11 静态断言static_assert，编译期断言。两个参数，一个是断言表达式，由于是在编译期间，所以断言表达式必须是常量表达式.一个是提示信息,可以自定义。
static_assert是C++的标准语法，不需要引用头文件。
*/

#include <iostream>
#include <cassert>

int main() {
  {
    int i = 22;
    assert(i != 22);
  }
  {
    const int i = 22;
    static_assert(i != 22, "i equals to 22");
  }
}