#ifndef Header_Guard_GUID_458E7EF3_7C10_4ABB_A552_2EB5E485D5EC
#define Header_Guard_GUID_458E7EF3_7C10_4ABB_A552_2EB5E485D5EC

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct A {
    double x;
};

struct {
    int x;
} s;

int main() {
    // decltype
    // 只分析不计算；双括号表示引用
    // 与using typedef配合使用
    //重用匿名类型

    // 推导4原则
    // 1 如果e是一个没有带括号的标记符表达式或者类成员访问表达式，那么的decltype（e）就是e所命名的实体的类型。此外，如果e是一个被重载的函数，则会导致编译错误。
    // 2 否则 ，假设e的类型是T，如果e是一个将亡值，那么decltype（e）为T &&
    // 3 否则，假设e的类型是T，如果e是一个左值，那么decltype（e）为T&。
    // 4 否则，假设e的类型是T，则decltype（e）为T。

    // 标记符: 指的是除去关键字、字面量等编译器需要使用的标记之外的程序员自己定义的标记，而单个标记符对应的表达式即为标记符表达式。例如：


    int var;
    A a;
    const A a1 = {1};

    const int&& f1();
    int f2();
    int f2(int a);

    // 推导1 标记符表达式和类成员访问表达式，推导为其类型
    decltype(1) i = 1; // int
    decltype(var) i1 = 1; // int
    decltype((var)) i2 = var; // 双括号 int&
    decltype(a.x) x1 = 1; // double
    decltype(a1) a11 = a1; // const A
    //decltype(f2) f; // 重载函数，报错

    // 推导2 将亡值，推导为右值引用
    decltype(f1()) r1 = 1; // const int&&

    // 推导3 左值，推导为类型的引用
    decltype(++var) i3 = var; // int&
    decltype("hello") str1 = "hello"; // const char(&)[6] 字符串字面值是常量左值

    // 推导4 其他推导为其类型
    decltype(f2()) r2; // int
    decltype(var++) i4; // int
    decltype(1) i5; // int


    // 与using / typedef合用，用于定义类型。
    using B = decltype(a);
    typedef decltype(a) C;

    // 重用匿名类型
    decltype(s) s1;

    // 与auto结合
    //C++11
    //  template<typename T, typename U>
    //  auto myFunc(T&& t, U&& u) -> decltype (forward<T>(t) + forward<U>(u)) {
    //    return forward<T>(t) + forward<U>(u);
    //  };
    //
    //  //C++14
    //  template<typename T, typename U>
    //  decltype(auto) myFunc(T&& t, U&& u) {
    //    return forward<T>(t) + forward<U>(u);
    //  };

    // 与auto比较
    // 1.auto忽略顶层const，decltype保留顶层const；
    // 2.对引用操作，auto推断出原有类型，decltype推断出引用；
    // 3.对解引用操作，auto推断出原有类型，decltype推断出引用；
    // 4.auto推断时会实际执行，decltype不会执行，只做分析。

    {
        // 1
        const int a = 0;
        auto b = a;
        decltype(a) bb = a;

        // 2
        int a1 = 1;
        int& b1 = a1;
        auto c = b1;
        decltype(b1) cc = b1;

        // 3
        int* p = &a1;
        auto p1 = *p;
        decltype(*p) p2 = a1;

        // 4
        cout << "before decltype a1: " << a1 << endl;
        decltype(a1++) a11 = 2; // 只分析，不计算
        cout << "after decltype a1: " << a1 << endl;
    }

    // 资料
    // https://docs.microsoft.com/en-us/previous-versions/dd537655(v=vs.140)

    system("pause");

    return 0;
}


#endif // Header_Guard_GUID_458E7EF3_7C10_4ABB_A552_2EB5E485D5EC
