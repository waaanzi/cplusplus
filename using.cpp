#include <iostream>
#include <memory>
#include <vector>
#include<functional>


class A {
 public:
  A() :m_(0) {}
  A(int n) :m_(n) {}
  virtual void show() {
    std::cout << "A show" << std::endl;
  }
  virtual void show(int n) {
    std::cout << "A show int " << n << std::endl;
  }

  void test() {
    std::cout << "A test" << std::endl;
  }
  void test(int n) {
    std::cout << "A show test " << n << std::endl;
  }
  int m_;
};

class AA : public A {
 public:
  using A::A;  // 场景2
  using A::show;  // 场景3
  using A::test;  // 场景3
  virtual void show() {
    std::cout << "AA show" << std::endl;
  }
  void test() {
    std::cout << "AA test" << std::endl;
  }
};


void count(int i) {
  std::cout << "count: " << i << std::endl;
}

int main() {

  /*1  using声明
  using+限定名称
    限定名称：包含名称空间的名称
    using Jill::fetch
  2 using编译指令
    using namespace Jill;
    using编译指令可以传递。
  C++11
  1 取代typedef
     using ptr = std::shared_ptr<A>;
  2 让父类同名函数在子类中以重载方式使用

  继承构造函数
  C++ 11中对C++98的using申明的扩展
  注意：
  多继承中可能出现的冲突问题；
  不适合基类构造函数是私有或者虚继承场景；
  使用了继承构造函数，编译器不会再生成默认构造函数；

  */
  // 1
  using std::cout;
  // 2
  using namespace std;
  // 3
  using intvec = std::vector<int>;
  // 4 继承构造函数中使用

  // 5
  /*
  如果重新定义派生类中的函数，将不只是使用相同的函数参数列表覆盖基类申明，无论参数列表是否相同，该操作将隐藏所有得同名基类方法。
  引出两条经验规则：
  第一，如果重新定义继承的方法，应确保与原来的原型完全相同，但如果返回类型是基类引用或者指针，则可以修改为指向派生类的引用或指针，
  这种特性称为返回类型协变（covariance of return type），因为允许返回类型随类型的变化而变化；
  第二，如果基类申明被重载了，则应在派生类中重新定义所有的基类版本。

  即注意隐藏的场景
    如果派生类的函数与基类的函数同名，但是参数不同。此时，不论有无virtual关键字，基类的函数将被隐藏。
    如果派生类的函数与基类的函数同名，并且参数也相同，但是基类函数没有virtual关键字。此时，基类的函数被隐藏。
  */


  AA aa;
  aa.show();
  aa.test();
  aa.show(1);
  aa.test(1);

  system("pause");

  return 0;
}
