/*
https://zh.cppreference.com/w/cpp/keyword/export
c++ export
C++11前 用于标注一个模板定义被导出，这允许在其他翻译单元中申明，但不定义同一模板
C++11起 不使用，并保留该关键字

http://www.uml.org.cn/c++/20112284.asp
任何时候都适用的20个C++技巧
技巧15：模板定义的位置在哪里？是.cpp文件吗？

通常情况下，你会在.h文件中声明函数和类，而将它们的定义放置在一个单独的.cpp文件中。但是在使用模板时，这种习惯性做法将变得不再有用，
因为当实例化一个模板时，编译器必须看到模板确切的定义，而不仅仅是它的声明。
因此，最好的办法就是将模板的声明和定义都放置在同一个.h文件中。这就是为什么所有的STL头文件都包含模板定义的原因。
另外一个方法就是使用关键字“export”！你可以在.h文件中，声明模板类和模板函数；在.cpp文件中，使用关键字export来定义具体的模板类对象和模板函数；
然后在其他用户代码文件中，包含声明头文件后，就可以使用该这些对象和函数了。例如：
  // output.h - 声明头文件
  template<class T> void output (const T& t);

  // out.cpp - 定义代码文件
  #include <****>
  export template<class T> void output (const T& t) {std::cerr << t;}

  //main.cpp:用户代码文件

  #include "output.h"
  void main() // 使用output()
  {
  output(4);
  output("Hello");
  }
某种程度上，这有点类似于为了访问其他编译单元（如另一代码文件）中普通类型的变量或对象而采用的关键字extern。
但是，这里还有一个不得不说的问题：并非所有的编译器都支持export关键字（我们最熟悉、最常用的两款编译器VS 和 GCC就是不支持export的典型代表）。
对于这种不确定，最好的方法就是采用解决方案一：声明定义放在一起，虽然这在某种程度上破坏了C++编程的优雅性。
分离编译模式（Separate Compilation Model）允许在一处翻译单元（Translation Unit）中定义（define）函数、类型、类对象等，
在另一处翻译单元引用它们。编译器（Compiler）处理完所有翻译单元后，链接器（Linker）接下来处理所有指向 extern 符号的引用，从而生成单一可执行文件。
该模式使得 C++ 代码编写得称心而优雅。
然而该模式却驯不服模板（Template）。标准要求编译器在实例化模板时必须在上下文中可以查看到其定义实体；
而反过来，在看到实例化模板之前，编译器对模板的定义体是不处理的——原因很简单，编译器怎么会预先知道 typename 实参是什么呢？
因此模板的实例化与定义体必须放到同一翻译单元中。
以优雅著称的 C++ 是不能容忍有此“败家玩意儿”好好活着的。标准 C++ 为此制定了“模板分离编译模式（Separation Model）”及 export 关键字。
然而由于 template 语义本身的特殊性使得 export 在表现的时候性能很次。
编译器不得不像 .net 和 java 所做的那样，为模板实体生成一个“中间伪代码（IPC，intermediate pseudo - code）”，使得其它翻译单元在实例化时可找到定义体；
而在遇到实例化时，根据指定的 typename 实参再将此 IPC 重新编译一遍，从而达到“分离编译”的目的。因此，该标准受到了几乎所有知名编译器供应商的强烈抵制。
谁支持 export 呢？Comeau C/C++ 和 Intel 7.x 编译器支持。
而以“百分百支持 ISO ”著称的 VS 和 GCC 却对此视而不见。真不知道这两大编译器“百分百支持”的是哪个版本的 ISO。
在 VS 2008 中，export 关键字在 IDE 中被标蓝，表示 VS IDE 认识它，而编译时，会用警告友情提示你“不支持该关键字”，
而配套的 MSDN 9 中的 C++ keywords 页则根本查不到该关键字；而在 VS 2010 中，就没那么客气了，尽管 IDE 中仍然会将之标蓝，但却会直截了当地报错。

*/
#include <iostream>
#include "export.hpp"

int main() {

  add(1, 1.2);
  system("pause");
  return 0;
}
